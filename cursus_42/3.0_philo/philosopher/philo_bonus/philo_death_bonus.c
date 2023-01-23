/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/23 12:42:19 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//	Algorythm that tries to keeps all philosophers alive
//	Philosophers actions:
void	keep_philo_alive(t_philo *philo)
{
	eat(philo);
	if (philo->times_eaten == philo->agora->n_times_must_eat
		&& philo->agora->n_times_must_eat)
		sem_post(philo->agora->meals_achieved);
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
	philo->is_alive = 0;
	sem_wait(philo->agora->dead);
	print_action(philo, "died");
	sem_post(philo->agora->finish);
}

//	Thread of every philosopher, his daily routine
void	*death_routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	while (1)
	{
		sem_wait(philo->status);
		sem_wait(philo->agora->print);
		if (time_now(philo->agora->init_time) - philo->last_meal_time
			>= (uint64_t)philo->agora->time_to_die)
		{
			take_philo_soul(philo);
			return (NULL);
		}
		sem_post(philo->status);
		sem_post(philo->agora->print);
	}
	return (NULL);
}
