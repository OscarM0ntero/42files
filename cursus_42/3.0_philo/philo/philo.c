/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:50 by omontero         ###   ########.fr       */
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

	s1 = ft_itoa(philo->agora->time);
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
	//	CHECK HERE AND IMPLEMENT EAT WITH USLEEP FOR EAT AND SLEEP< MAYBE REMOVE ACTION COUNTER
	if (philo->action == 3)
	{
		if (philo->num % 2 == 0)
			usleep(500);
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, "fork");
		philo->right_fork->avaliable = 0;
		pthread_mutex_lock(&philo->left_fork);
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

//	Checks how many times did a philosopher ate, if there is a limit and he
//	achieved it, it returns 1, else returns 0
int	check_times_eaten(t_philo *philo)
{
	if (philo->times_eaten == philo->agora->n_times_must_eat)
		return (1);
	return (0);
}

//	Thread of every philosopher
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->num % 2 == 0)
		usleep(500);
	while (philo->is_alive)
	{
		if (philo->agora->n_times_must_eat)
			if (check_times_eaten(philo))
				break ;
		keep_philo_alive(philo);
	}
	return (0);
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
		agora->philos[i].times_eaten = 0;
		agora->philos[i].last_time_check = agora->time;
		if (i == 0)
			agora->philos[i].left_fork
				= &agora->philos[agora->n_philos - 1].fork;
		else
			agora->philos[i].left_fork = &agora->philos[i - 1].fork;
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
