/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/16 15:47:46 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop(t_agora *agora)
{
	while (agora->time != 10000)
	{
		usleep(1000);
		agora->time += 1;
		printf("%ld\n", agora->time);
	}
}

void	*philo_routine(void *arg)
{
	t_agora	*agora;

	agora = arg;
	while (agora->time != 5000)
	{
	}
	agora->philos[0].action = 1;
	printf("AAAAAAAA\n");
	return (NULL);
}

void	init_philos(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
	{
		agora->philos[i].num = i + 1;
		agora->philos[i].is_alive = 1;
		agora->philos[i].action = 0;
		pthread_create(&agora->philos[i].thread, NULL, philo_routine, agora);
	}
}

void	init_agora(t_agora *agora, char **argv)
{
	agora->time = 0;
	agora->n_philos = ft_atoi(argv[1]);
	agora->time_to_die = ft_atoi(argv[2]);
	agora->time_to_eat = ft_atoi(argv[3]);
	agora->time_to_sleep = ft_atoi(argv[4]);
	agora->philos = (t_philo *)malloc(agora->n_philos * sizeof(t_philo));
}

void	print_philos(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
	{
		printf("%d %d %d\n", agora->philos[i].num,
			agora->philos[i].is_alive, agora->philos[i].action);
	}
}

int	main(int argc, char **argv)
{
	t_agora	agora;

	init_agora(&agora, argv);
	init_philos(&agora);
	loop(&agora);
	print_philos(&agora);
	return (EXIT_SUCCESS);
}
