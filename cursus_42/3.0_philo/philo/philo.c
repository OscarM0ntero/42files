/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/19 01:32:28 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Returns the actual time value in ms
uint64_t	time_now(uint64_t t)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - t);
}

//	Sleeps the amount of time in ms that we have introduced
void	my_sleep(uint64_t ms)
{
	uint64_t	t;

	t = time_now(0);
	while ((time_now(0) - t) < ms)
		usleep(1);
}

//	Returns a string with the actual time stamp in ms and
//	the number of the current philosopher
char	*get_time_and_philo(t_philo *philo)
{
	char	*s1;
	char	*s2;
	char	*tmp;

	s1 = ft_itoa(time_now(philo->agora->init_time));
	s2 = ft_itoa(philo->num);
	tmp = s1;
	s1 = ft_strjoin(s1, "  ms ");
	free (tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, "		");
	free (tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free (tmp);
	free (s2);
	return (s1);
}

//	Prints philosopher action changes
void	print_action(t_philo *philo, char *action)
{
	char	*s;
	char	*f;

	s = get_time_and_philo(philo);
	pthread_mutex_lock(&philo->agora->print);
	if (ft_strncmp(action, "fork", 4) == 0)
		f = ft_strjoin(s, " has taken a fork\n");
	else if (ft_strncmp(action, "eat", 3) == 0)
		f = ft_strjoin(s, " is eating\n");
	else if (ft_strncmp(action, "sleep", 5) == 0)
		f = ft_strjoin(s, " is sleeping\n");
	else if (ft_strncmp(action, "think", 5) == 0)
		f = ft_strjoin(s, " is thinking\n");
	else if (ft_strncmp(action, "died", 4) == 0)
		f = ft_strjoin(s, " died\n");
	if (!philo->agora->corpse_found || (philo->agora->corpse_found
			&& !ft_strncmp(action, "died", 4)))
		write (1, f, ft_strlen(f));
	pthread_mutex_unlock(&philo->agora->print);
	free (s);
	free (f);
}

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
	{
		philo->agora->meals_achieved = 1;
		return ;
	}
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
		>= philo->agora->time_to_die)
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

	philo = arg;
	if (philo->num % 2 == 0)
		my_sleep(1);
	while (!philo->agora->corpse_found && !philo->agora->meals_achieved)
		keep_philo_alive(philo);
	return (0);
}

//	Initializes all the philosophers with basic values, and their forks
void	init_philos(t_agora *agora)
{
	int	i;

	i = -1;
	while (++i < agora->n_philos)
		pthread_mutex_init(&agora->philos[i].fork, NULL);
	i = -1;
	while (++i < agora->n_philos)
	{
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
		pthread_create(&agora->philos[i].thread, NULL, philo_routine,
			&agora->philos[i]);
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

//	Terminates the threads, useful when it finishes when there has been no death
void	join_threads(t_agora *agora)
{
	int	i;

	i = 0;
	while (i < agora->n_philos)
	{
		pthread_join(agora->philos[i].thread, NULL);
		i++;
	}
}

//	Main
int	main(int argc, char **argv)
{
	t_agora	agora;
	int		i;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	init_agora(&agora, argv);
	init_philos(&agora);
	while (!agora.corpse_found && !agora.meals_achieved)
	{
		i = 0;
		while (i < agora.n_philos)
		{
			take_philo_soul(&agora.philos[i]);
			if (!agora.philos[i].is_alive)
				break ;
			i++;
		}
		usleep(100);
	}
	if (!agora.corpse_found)
		join_threads(&agora);
	free(agora.philos);
	return (0);
}
