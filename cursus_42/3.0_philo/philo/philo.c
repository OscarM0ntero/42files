/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/17 00:29:49 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Checks the pulse of all philosophers, if everyone is OK, returns 1, else 0
int	check_pulse(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
	{
		if (agora->philos[i].is_alive == 0)
			return (0);
	}
	return (1);
}

int	check_dead_body(t_agora *agora)
{
	int	i;

	i = 0;
	while (i < agora->n_philos && agora->philos[i].is_alive != 0)
		i++;
	return (agora->philos[i].num);
}

//	Loops the clock and keep it running while all philosophers are alive
void	loop(t_agora *agora)
{
	char	*tmp;

	while (check_pulse(agora))
	{
		usleep(1000);
		agora->time += 1;
		printf("%ld ms\n", agora->time);
	}
	ft_putnbr_fd(agora->time, 1);
	write(1, "		", 2);
	ft_putnbr_fd(check_dead_body(agora), 1);
	write (1, " is dead\n", 9);
}
//	Should print the death when happens

//	Algorythm that tries to keeps all philosophers alive
void	keep_philo_alive(t_philo *philo)
{
	t_agora	*agora;

	agora = philo->agora;
	if (agora->n_philos - agora->forks_in_use >= 2 && philo->action == 3)
	{
		philo->action = 1;
		philo->need_print = 1;
		agora->forks_in_use += 2;
	}
	else if ()
	{
		//	continuar calculando cada cambio de accion
	}
}

//	Philosophers actions:
//	1 - eat		2- sleep	3 - think
void	readjust_philo(t_philo *philo)
{
	t_agora	*agora;

	agora = philo->agora;
	while (philo->last_time_check == agora->time)
	{		
	}
	philo->last_time_check = agora->time;
	if (philo->action == 1)
		philo->time_eating++;
	else if (philo->action == 2)
	{
		philo->time_sleeping++;
		philo->time_since_eat++;
	}
	else if (philo->action == 3)
		philo->time_since_eat++;
	if (philo->time_since_eat >= agora->time_to_die)
		philo->is_alive = 0;
}

//	Thread of every philosopher
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->is_alive)
	{
		readjust_philo(philo);
		keep_philo_alive(philo);
	}
	printf("AAAAAAAA\n");
	return (NULL);
}

//	Initializes all the philosophers with basic values
void	init_philos(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
	{
		agora->philos[i].num = i + 1;
		agora->philos[i].is_alive = 1;
		agora->philos[i].action = 3;
		agora->philos[i].agora = agora;
		agora->philos[i].time_since_eat = 0;
		agora->philos[i].time_eating = 0;
		agora->philos[i].time_sleeping = 0;
		agora->philos[i].last_time_check = agora->time;
		agora->philos[i].forks_in_hand = 0;
		agora->philos[i].need_print = 0;
		pthread_create(&agora->philos[i].thread, NULL, philo_routine,
			&agora->philos[i]);
	}
}

//	Initializes the agora for the philosophers to gather arround
void	init_agora(t_agora *agora, char **argv)
{
	agora->time = 0;
	agora->n_philos = ft_atoi(argv[1]);
	agora->time_to_die = ft_atoi(argv[2]);
	agora->time_to_eat = ft_atoi(argv[3]);
	agora->time_to_sleep = ft_atoi(argv[4]);
	agora->forks_in_use = 0;
	if (argv[5])
		agora->n_times_must_eat = ft_atoi(argv[5]);
	agora->philos = (t_philo *)malloc(agora->n_philos * sizeof(t_philo));
}

//	Print philosophers status
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

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	init_agora(&agora, argv);
	init_philos(&agora);
	loop(&agora);
	print_philos(&agora);
	return (EXIT_SUCCESS);
}
