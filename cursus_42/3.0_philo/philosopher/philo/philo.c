/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/03/20 12:08:53 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Terminates the threads, useful when it finishes when there has been no death
void	join_threads(t_agora *agora)
{
	int	i;

	i = 0;
	while (i < agora->n_philos && !agora->corpse_found)
	{
		pthread_join(agora->philos[i].thread, NULL);
		i++;
	}
}

// Checks constantly if the philos are alive
void	check_on_philos(t_agora *agora)
{
	int	i;
	int	c;

	while (!agora->corpse_found && !agora->meals_achieved)
	{
		i = 0;
		c = 0;
		while (i < agora->n_philos)
		{
			take_philo_soul(&agora->philos[i]);
			if (!agora->philos[i].is_alive)
				break ;
			c += agora->philos[i].enough_meals;
			i++;
		}
		if (c == agora->n_philos)
			agora->meals_achieved = 1;
		usleep(10);
	}
}

//	Main
int	main(int argc, char **argv)
{
	t_agora	agora;

	if (argc < 5 || argc > 6)
		return (write(2, "Invalid amount of agruments.\n", 29), EXIT_FAILURE);
	if (init_agora(&agora, argv))
		return (1);
	init_philos(&agora);
	init_threads(&agora);
	check_on_philos(&agora);
	join_threads(&agora);
	free(agora.philos);
	return (0);
}
