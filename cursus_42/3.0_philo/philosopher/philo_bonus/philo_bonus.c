/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/23 14:54:54 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	join_free(t_agora *agora)
{
	int		i;
	int		status;

	i = -1;
	while (++i < agora->n_philos)
	{
		waitpid(agora->philos[i].pid, &status, 0);
		sem_close(agora->philos[i].status);
	}
	free(agora->philos);
	sem_close(agora->finish);
	sem_close(agora->forks);
	sem_close(agora->meals_achieved);
	sem_close(agora->print);
	sem_close(agora->dead);
}

void	show_leaks(void)
{
	system("leaks -q a.out");
}

//	Main
int	main(int argc, char **argv)
{
	t_agora		agora;
	pthread_t	thread;

	if (argc < 5 || argc > 6)
		return (write(2, "Invalid amount of agruments.\n", 29), EXIT_FAILURE);
	if (init_agora(&agora, argv))
		return (1);
	init_philos(&agora);
	init_semaphores(&agora);
	init_threads(&agora);
	if (agora.n_times_must_eat != 0)
		pthread_create(&thread, NULL, meals_control, &agora);
	pthread_create(&thread, NULL, finish, &agora);
	join_free(&agora);
	return (0);
}
