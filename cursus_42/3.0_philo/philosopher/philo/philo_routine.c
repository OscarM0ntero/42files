/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/23 12:58:54 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Manages the eat process of the philosopher, using mutex to manage the forks
//	and waits for them to be avaliables, and releasing them once he has finished
//	eating
void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action(philo, "fork");
	if (philo->agora->n_philos == 1)
	{
		my_sleep(philo->agora->time_to_die);
		print_action(philo, "died");
		philo->agora->corpse_found = 1;
	}
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "fork");
	philo->last_meal_time = time_now(philo->agora->init_time);
	philo->times_eaten++;
	usleep(100);
	print_action(philo, "eat");
	my_sleep(philo->agora->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->left_fork);
}

//	Algorythm that tries to keeps all philosophers alive
//	Philosophers actions:
void	keep_philo_alive(t_philo *philo)
{
	eat(philo);
	if (philo->times_eaten == philo->agora->n_times_must_eat
		&& philo->agora->n_times_must_eat)
		philo->enough_meals = 1;
	print_action(philo, "sleep");
	my_sleep(philo->agora->time_to_sleep);
	print_action(philo, "think");
}

//	Checks how many times did a philosopher ate, if there is a limit and he
//	achieved it, it returns 1, else returns 0
int	check_times_eaten(t_philo *philo)
{
	if (philo->times_eaten == philo->agora->n_times_must_eat)
		return (1);
	return (0);
}

//	Checks if philosopher time has come and kills him of hunger if he didn't
//	ate in the corresponding time
void	take_philo_soul(t_philo *philo)
{
	if (time_now(philo->agora->init_time) - philo->last_meal_time
		>= (uint64_t)philo->agora->time_to_die)
	{
		philo->is_alive = 0;
		philo->agora->corpse_found = philo->num;
		print_action(philo, "died");
	}
}

//	Thread of every philosopher, his daily routine
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2 == 0)
		usleep(1000);
	while (!philo->agora->corpse_found
		&& !philo->agora->meals_achieved)
		keep_philo_alive(philo);
	return (0);
}
