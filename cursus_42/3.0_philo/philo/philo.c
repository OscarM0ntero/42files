/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/17 23:30:33 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "signal.h"
#include "wait.h"

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

//	Returns the number of the dead philosopher
int	check_dead_body(t_agora *agora)
{
	int	i;

	i = 0;
	while (i < agora->n_philos && agora->philos[i].is_alive != 0)
		i++;
	return (agora->philos[i].num);
}

//	Returns a string with the actual time stamp in ms and
//	the number of the current philosopher
char	*get_time_and_philo(t_philo *philo)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	t_agora	*agora;

	agora = philo->agora;
	s1 = ft_itoa(agora->time);
	s2 = ft_itoa(philo->num);
	tmp = s1;
	s1 = ft_strjoin(s1, "  ms ");
	free (tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, "	");
	free (tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free (tmp);
	free (s2);
	return (s1);
}

//	Prints philosopher action changes
void	print_action(t_philo *philo, t_agora *agora)
{
	char	*s;

	s = get_time_and_philo(philo);
	//write (1, "		Free forks : ", 15);
	//write (1, ft_itoa(agora->n_philos - agora->forks_in_use),
	//	ft_strlen(ft_itoa(agora->n_philos - agora->forks_in_use)));
	//write (1, "\n", 1);
	if (philo->action == 1)
	{
		write (1, s, ft_strlen(s));
		write (1, " has taken a fork\n", 18);
		write (1, s, ft_strlen(s));
		write (1, " has taken a fork\n", 18);
		write (1, s, ft_strlen(s));
		write (1, " is eating\n", 11);
	}
	else if (philo->action == 2)
	{
		write (1, s, ft_strlen(s));
		write (1, " is sleeping\n", 13);
	}
	else if (philo->action == 3)
	{
		write (1, s, ft_strlen(s));
		write (1, " is thinking\n", 13);
	}
	free (s);
	philo->need_print = 0;
}

void	check_changes(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
	{
		if (agora->philos[i].need_print)
			print_action(&agora->philos[i], agora);
	}
}

//	Loops the clock and keep it running while all philosophers are alive
void	loop(t_agora *agora)
{
	char	*s;
	while (check_pulse(agora))
	{
		check_changes(agora);
		usleep(1000);
		agora->time += 1;
	}
	s = get_time_and_philo(&agora->philos[check_dead_body(agora)]);
	write (1, s, ft_strlen(s));
	write (1, " is dead\n", 9);
	free (s);
}
//	Should print the death when happens

//	Algorythm that tries to keeps all philosophers alive
//	Philosophers actions:
//	1 - eat		2- sleep	3 - think
void	keep_philo_alive(t_philo *philo)
{
	t_agora	*agora;

	agora = philo->agora;
	if (philo->action == 3 && agora->n_philos - agora->forks_in_use >= 2)
	{
		//if (philo->num % 2 == 0)
		//	usleep(1);
		while (!philo->right_fork->avaliable)
		{
		}
		philo->right_fork->avaliable = 0;
		while (!philo->left_fork->avaliable)
		{
		}
		philo->left_fork->avaliable = 0;
		philo->action = 1;
		philo->need_print = 1;
		philo->times_eaten++;
	}
	else if (philo->action == 1 && philo->time_eating == agora->time_to_eat)
	{
		philo->action = 2;
		philo->time_eating = 0;
		philo->time_since_eat = 0;
		philo->need_print = 1;
		philo->right_fork->avaliable = 1;
		philo->left_fork->avaliable = 1;
	}
	else if (philo->action == 2 && philo->time_sleeping == agora->time_to_sleep)
	{
		philo->action = 3;
		philo->time_sleeping = 0;
		philo->need_print = 1;
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

//	Checks how many times did a philosopher ate, if there is a limit and he
//	achieved it, it returns 1, else returns 0
int	check_times_eaten(t_philo *philo)
{
	t_agora	*agora;

	agora = philo->agora;
	if (philo->times_eaten == agora->n_times_must_eat)
	{
		//printf("%i ha comido %i veces \n", philo->num, philo->times_eaten);
		return (1);
	}
	return (0);
}

//	Thread of every philosopher
void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_agora	*agora;

	philo = arg;
	agora = philo->agora;
	while (philo->is_alive)
	{
		if (agora->n_times_must_eat)
			if (check_times_eaten(philo))
				exit(EXIT_SUCCESS);
		readjust_philo(philo);
		//usleep(philo->num * 10);
		keep_philo_alive(philo);
	}
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
		agora->philos[i].times_eaten = 0;
		agora->philos[i].last_time_check = agora->time;
		agora->philos[i].forks_in_hand = 0;
		agora->philos[i].need_print = 0;
		agora->forks[i].avaliable = 1;
		agora->philos[i].right_fork = &agora->forks[i];
		if (i == 0)
			agora->philos[i].left_fork = &agora->forks[agora->n_philos - 1];
		else
			agora->philos[i].left_fork = &agora->forks[i - 1];
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
	else
		agora->n_times_must_eat = 0;
	agora->philos = (t_philo *)malloc(agora->n_philos * sizeof(t_philo));
	agora->forks = (t_fork *)malloc(agora->n_philos * sizeof(t_fork));
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
	//print_philos(&agora);
	return (EXIT_SUCCESS);
}
