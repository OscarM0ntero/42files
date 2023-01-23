/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/23 12:36:20 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//	Manages the eat process of the philosopher, using mutex to manage the forks
//	and waits for them to be avaliables, and releasing them once he has finished
//	eating
void	eat(t_philo *philo)
{
	sem_wait(philo->agora->forks);
	print_action(philo, "fork");
	if (philo->agora->n_philos == 1)
	{
		my_sleep(philo->agora->time_to_die);
		print_action(philo, "died");
	}
	sem_wait(philo->agora->forks);
	print_action(philo, "fork");
	sem_wait(philo->status);
	philo->last_meal_time = time_now(philo->agora->init_time);
	philo->times_eaten++;
	print_action(philo, "eat");
	my_sleep(philo->agora->time_to_eat);
	sem_post(philo->agora->forks);
	sem_post(philo->agora->forks);
	sem_post(philo->status);
}

void	*finish(void *arg)
{
	t_agora		*agora;
	int			i;

	agora = arg;
	sem_wait(agora->finish);
	i = -1;
	while (++i < agora->n_philos)
		kill(agora->philos[i].pid, SIGTERM);
	return (NULL);
}

void	*meals_control(void *arg)
{
	t_agora		*agora;
	int			i;

	agora = arg;
	i = -1;
	while (++i < agora->n_philos)
		sem_wait(agora->meals_achieved);
	sem_post(agora->finish);
	return (NULL);
}

void	routine(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, death_routine, philo);
	if (philo->num % 2 == 0)
		usleep(1000);
	while (1)
		keep_philo_alive(philo);
	exit (0);
}
