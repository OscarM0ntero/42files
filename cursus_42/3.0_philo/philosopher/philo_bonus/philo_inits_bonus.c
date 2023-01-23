/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_inits_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/23 12:35:24 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphores(t_agora *agora)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("dead");
	sem_unlink("finish");
	sem_unlink("meals_achieved");
	agora->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, agora->n_philos);
	agora->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	agora->dead = sem_open("dead", O_CREAT | O_EXCL, 0644, 1);
	agora->finish = sem_open("finish", O_CREAT | O_EXCL, 0644, 0);
	agora->meals_achieved = sem_open("meals_achieves", O_CREAT, 0600, 1);
}

//	Initializes all the philosophers with basic values, and their forks
void	init_philos(t_agora *agora)
{
	int		i;
	char	*s;

	i = -1;
	while (++i < agora->n_philos)
	{
		agora->philos[i].pid = -1;
		agora->philos[i].num = i + 1;
		agora->philos[i].is_alive = 1;
		agora->philos[i].agora = agora;
		agora->philos[i].times_eaten = 0;
		agora->philos[i].enough_meals = 0;
		agora->philos[i].last_meal_time = time_now(agora->init_time);
		s = ft_itoa(i + 1);
		agora->philos[i].status = sem_open(s, O_CREAT | O_EXCL, 0644, 1);
		free (s);
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
	if (argv[5])
		agora->n_times_must_eat = ft_atoi(argv[5]);
	else
		agora->n_times_must_eat = 0;
	agora->philos = (t_philo *)malloc(agora->n_philos * sizeof(t_philo));
	agora->forks = NULL;
	agora->dead = NULL;
	agora->print = NULL;
	agora->finish = NULL;
	agora->meals_achieved = NULL;
}

void	init_threads(t_agora *agora)
{
	int	i;

	i = 0;
	while (i < agora->n_philos)
	{
		agora->philos[i].pid = fork();
		if (agora->philos[i].pid == 0)
		{
			routine(&agora->philos[i]);
			exit (0);
		}
		i++;
		usleep(100);
	}
}
