/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/23 02:23:10 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_taken(t_map *map, size_t x, size_t y)
{
	map->coins.coin_t_x = x;
	map->coins.coin_t_y = y;
	map->move = 0;
	map->coins.coin_taked++;
}

void	move_up(t_map *map)
{
	map->mv_count++;
	if (map->structure[map->p_y - 1][map->p_x] == '0')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->structure[map->p_y][map->p_x] = 'P';
	}
	else if (map->structure[map->p_y - 1][map->p_x] == 'C')
		coin_taken(map, map->p_x, map->p_y - 1);
	else if (map->structure[map->p_y - 1][map->p_x] == 'E')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->structure[map->p_y][map->p_x] = 'P';
		map->map_finished = 1;
	}
	else if (map->structure[map->p_y - 1][map->p_x] == 'V')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->game_over = 1;
	}
}

void	move_right(t_map *map)
{
	map->mv_count++;
	if (map->structure[map->p_y][map->p_x + 1] == '0')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->structure[map->p_y][map->p_x] = 'P';
	}
	else if (map->structure[map->p_y][map->p_x + 1] == 'C')
		coin_taken(map, map->p_x + 1, map->p_y);
	else if (map->structure[map->p_y][map->p_x + 1] == 'E')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->structure[map->p_y][map->p_x] = 'P';
		map->map_finished = 1;
	}
	else if (map->structure[map->p_y][map->p_x + 1] == 'V')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->game_over = 1;
	}
}

void	move_down(t_map *map)
{
	map->mv_count++;
	if (map->structure[map->p_y + 1][map->p_x] == '0')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->structure[map->p_y][map->p_x] = 'P';
	}
	else if (map->structure[map->p_y + 1][map->p_x] == 'C')
		coin_taken(map, map->p_x, map->p_y + 1);
	else if (map->structure[map->p_y + 1][map->p_x] == 'E')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->structure[map->p_y][map->p_x] = 'P';
		map->map_finished = 1;
	}
	else if (map->structure[map->p_y + 1][map->p_x] == 'V')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->game_over = 1;
	}
}

void	move_left(t_map *map)
{
	map->mv_count++;
	if (map->structure[map->p_y][map->p_x - 1] == '0')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->structure[map->p_y][map->p_x] = 'P';
	}
	else if (map->structure[map->p_y][map->p_x - 1] == 'C')
		coin_taken(map, map->p_x - 1, map->p_y);
	else if (map->structure[map->p_y][map->p_x - 1] == 'E')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->structure[map->p_y][map->p_x] = 'P';
		map->map_finished = 1;
	}
	else if (map->structure[map->p_y][map->p_x - 1] == 'V')
	{
		map->structure[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->game_over = 1;
	}
}

void	move(int dir, t_map *map)
{
	if (dir == 1 && map->structure[map->p_y - 1][map->p_x] != '1')
		move_up(map);
	else if (dir == 2 && map->structure[map->p_y][map->p_x + 1] != '1')
		move_right(map);
	else if (dir == 3 && map->structure[map->p_y + 1][map->p_x] != '1')
		move_down(map);
	else if (dir == 4 && map->structure[map->p_y][map->p_x - 1] != '1')
		move_left(map);
	if (map->game_over || map->map_finished)
		map->move = 0;
	print_map(map);
}
