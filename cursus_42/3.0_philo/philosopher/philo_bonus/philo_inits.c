/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/19 13:19:38 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Initializes all the philosophers with basic values, and their forks
void	init_philos(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
	{
		pthread_mutex_init(&agora->philos[i].fork, NULL);
		agora->philos[i].num = i + 1;
		agora->philos[i].is_alive = 1;
		agora->philos[i].agora = agora;
		agora->philos[i].times_eaten = 0;
		agora->philos[i].last_meal_time = time_now(agora->init_time);
		if (i == 0)
			agora->philos[i].left_fork
				= &agora->philos[agora->n_philos - 1].fork;
		else
			agora->philos[i].left_fork = &agora->philos[i - 1].fork;
	}
}

//	Initializes the agora for the philosophers to gather arround
void	init_agora(t_agora *agora, char **argv)
{
	agora->init_time = time_now(0);
	agora->n_philos = ft_atoi(argv[1]);
	agora->time_to_die = ft_atoi(argv[2]);
	agora->time_to_eat = ft_atoi(argv[3]);
	agora->time_to_sleep = ft_atoi(argv[4]);
	agora->meals_achieved = 0;
	agora->corpse_found = 0;
	if (argv[5])
		agora->n_times_must_eat = ft_atoi(argv[5]);
	else
		agora->n_times_must_eat = 0;
	agora->philos = (t_philo *)malloc(agora->n_philos * sizeof(t_philo));
	pthread_mutex_init(&agora->print, NULL);
}

void	init_threads(t_agora *agora)
{
	int	i;

	i = 0;
	while (i < agora->n_philos)
	{
		pthread_create(&agora->philos[i].thread, NULL, philo_routine,
			&agora->philos[i]);
		i++;
	}
}
