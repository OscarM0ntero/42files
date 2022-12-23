/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/23 00:26:29 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Error code
*	1 = Empty file
*	2 = Different number of chars per line
*	3 = Invalid char found !(0, 1, P, E, C)
*	4 = Not surrounded by 1s (not closed)
*	5 = No player (P) in map
*	6 = More than one player (P) in map
*	7 = No exit (E) in map
*	8 = No coin (C) in map
*/

int	error_handler(int error)
{
	if (error == 1)
		return (write(1, "Error. Empty file.\n", 19), 1);
	else if (error == 2)
		return (printf("Error. Different lines lenghts.\n"), 1);
	else if (error == 3)
		return (printf("Error. Invalid char in map (Allowed: 01PEC).\n"), 1);
	else if (error == 4)
		return (printf("Error. Map not surrounded by 1's.\n"), 1);
	else if (error == 5)
		return (printf("Error. Player (P) not found in map.\n"), 1);
	else if (error == 6)
		return (printf("Error. More than 1 player in map.\n"), 1);
	else if (error == 7)
		return (printf("Error. Exit (E) not found in map.\n"), 1);
	else if (error == 8)
		return (printf("Error. Coin (C) not found in map.\n"), 1);
	else if (error == 9)
		return (printf("Fallo aqui xd\n"), 1);
	else
		printf("No fallo\n");
	return (0);
}

void	check_player_coords(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (++i < (int)map->n_lines && !map->error)
	{
		j = -1;
		while (++j < (int)map->n_chars && !map->error)
		{
			if (map->structure[i][j] == 'P' && !map->error)
			{
				if (++count == 1)
				{
					map->p_x = (size_t)j;
					map->p_y = (size_t)i;
				}
				else if (count == 2)
					map->error = 6;
			}
		}
	}
	if (!count && !map->error)
		map->error = 5;
}

void	check_exit_and_coin(t_map *map)
{
	int		i;
	int		j;
	size_t	c_coin;
	size_t	c_exit;

	c_coin = 0;
	c_exit = 0;
	i = -1;
	while (++i < (int)map->n_lines && !map->error)
	{
		j = -1;
		while (++j < (int)map->n_chars && !map->error)
		{
			if (map->structure[i][j] == 'E' && !map->error)
				c_exit++;
			if (map->structure[i][j] == 'C' && !map->error)
				c_coin++;
		}
	}
	if (!c_exit && !map->error)
		map->error = 7;
	else if (!c_coin && !map->error)
		map->error = 8;
	map->coins.n_coins = c_coin;
}

void	check_enemies(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (int)map->n_lines)
	{
		j = -1;
		while (++j < (int)map->n_chars)
		{
			if (map->structure[i][j] == 'V')
				map->n_enemies++;
		}
	}
}
