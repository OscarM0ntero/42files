/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/07 20:29:31 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_taken(t_map *map, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	map->str[map->p_y][map->p_x] = '0';
	map->p_x = x;
	map->p_y = y;
	map->str[map->p_y][map->p_x] = 'P';
	while (i < map->n_extra)
	{
		if (map->mx_add[i].c == 'C' && map->mx_add[i].x == map->p_x
			&& map->mx_add[i].y == map->p_y)
			mlx_draw_texture(map->mx_add[i].img, &map->sprites.collect_2->texture, 0, 0);
		i++;
	}
	map->coins.c_count++;
}

void	refresh_player(t_map *map, int dir)
{
	if (!map->p_look)
		mlx_draw_texture(map->mx_add[0].img,
			&map->sprites.player_back->texture, 0, 0);
	else
		mlx_draw_texture(map->mx_add[0].img,
			&map->sprites.player->texture, 0, 0);
	map->mx_add[0].x = map->p_x;
	map->mx_add[0].y = map->p_y;
	
	if (dir == 1)
		map->mx_add[0].img->instances[0].y -= IMG_H;
	else if (dir == 2)
		map->mx_add[0].img->instances[0].x += IMG_W;
	else if (dir == 3)
		map->mx_add[0].img->instances[0].y += IMG_H;
	else if (dir == 4)
		map->mx_add[0].img->instances[0].x -= IMG_W;
}

//void	player_killed(t_map *map);

void	move_up(t_map *map)
{
	map->mv_count++;
	if (map->str[map->p_y - 1][map->p_x] == '0'
		|| (map->str[map->p_y - 1][map->p_x] == 'E'
		&& map->coins.n_coins == map->coins.c_count))
	{
		if (map->str[map->p_y - 1][map->p_x] == 'E'
			&& map->coins.n_coins == map->coins.c_count)
			map->map_finished = 1;
		map->str[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->str[map->p_y][map->p_x] = 'P';
		refresh_player(map, 1);
	}
	else if (map->str[map->p_y - 1][map->p_x] == 'C')
	{
		coin_taken(map, map->p_x, map->p_y - 1);
		refresh_player(map, 1);
	}
	else if (map->str[map->p_y - 1][map->p_x] == 'V')
	{
		map->str[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->game_over = 1;
		map->mx_add[0].img->enabled = 0;
	}
}

void	move_right(t_map *map)
{
	map->mv_count++;
	if (map->str[map->p_y][map->p_x + 1] == '0'
		|| (map->str[map->p_y][map->p_x + 1] == 'E'
		&& map->coins.n_coins == map->coins.c_count))
	{
		if ((map->str[map->p_y][map->p_x + 1] == 'E'
			&& map->coins.n_coins == map->coins.c_count))
			map->map_finished = 1;
		map->str[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->str[map->p_y][map->p_x] = 'P';
		refresh_player(map, 2);
	}
	else if (map->str[map->p_y][map->p_x + 1] == 'C')
	{
		coin_taken(map, map->p_x + 1, map->p_y);
		refresh_player(map, 2);
	}
	else if (map->str[map->p_y][map->p_x + 1] == 'V')
	{
		map->str[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->game_over = 1;
		map->mx_add[0].img->enabled = 0;
	}
}

void	move_down(t_map *map)
{
	map->mv_count++;
	if (map->str[map->p_y + 1][map->p_x] == '0'
		|| (map->str[map->p_y + 1][map->p_x] == 'E'
		&& map->coins.n_coins == map->coins.c_count))
	{
		if (map->str[map->p_y + 1][map->p_x] == 'E'
			&& map->coins.n_coins == map->coins.c_count)
			map->map_finished = 1;
		map->str[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->str[map->p_y][map->p_x] = 'P';
		refresh_player(map, 3);
	}
	else if (map->str[map->p_y + 1][map->p_x] == 'C')
	{
		coin_taken(map, map->p_x, map->p_y + 1);
		refresh_player(map, 3);
	}
	else if (map->str[map->p_y + 1][map->p_x] == 'V')
	{
		map->str[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->game_over = 1;
		map->mx_add[0].img->enabled = 0;
	}
}

void	move_left(t_map *map)
{
	map->mv_count++;
	if (map->str[map->p_y][map->p_x - 1] == '0'
		|| (map->str[map->p_y][map->p_x - 1] == 'E'
		&& map->coins.n_coins == map->coins.c_count))
	{
		if (map->str[map->p_y][map->p_x - 1] == 'E'
			&& map->coins.n_coins == map->coins.c_count)
			map->map_finished = 1;
		map->str[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->str[map->p_y][map->p_x] = 'P';
		refresh_player(map, 4);
	}
	else if (map->str[map->p_y][map->p_x - 1] == 'C')
	{
		coin_taken(map, map->p_x - 1, map->p_y);
		refresh_player(map, 4);
	}
	else if (map->str[map->p_y][map->p_x - 1] == 'V')
	{
		map->str[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->game_over = 1;
		map->mx_add[0].img->enabled = 0;
	}
}

void	move(int dir, t_map *map)
{
	char	**s;
	size_t	x;
	size_t	y;

	s = map->str;
	x = map->p_x;
	y = map->p_y;
	if (dir == 2)
		map->p_look = 1;
	else if (dir == 4)
		map->p_look = 0;
	if (dir == 1 && ((((s[y - 1][x] != '1') && s[y - 1][x] != 'E'))
		|| ((s[y - 1][x] == 'E' && map->coins.c_count == map->coins.n_coins))))
		move_up(map);
	else if (dir == 2 && ((((s[y][x + 1] != '1') && s[y][x + 1] != 'E'))
		|| ((s[y][x + 1] == 'E' && map->coins.c_count == map->coins.n_coins))))
		move_right(map);
	else if (dir == 3 && ((((s[y + 1][x] != '1') && s[y + 1][x] != 'E'))
		|| ((s[y + 1][x] == 'E' && map->coins.c_count == map->coins.n_coins))))
		move_down(map);
	else if (dir == 4 && ((((s[y][x - 1] != '1') && s[y][x - 1] != 'E'))
		|| ((s[y][x - 1] == 'E' && map->coins.c_count == map->coins.n_coins))))
		move_left(map);
	if (map->game_over || map->map_finished)
		map->move = 0;
	refresh_player(map, 0);
	//print_map(map);
}
