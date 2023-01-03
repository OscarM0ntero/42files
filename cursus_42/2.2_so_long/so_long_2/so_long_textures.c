/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/03 20:49:08 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*xpm_t	*floor_select(t_map *map, size_t x, size_t y, size_t frame)
{
	if (x % 2 == 0 && y % 2 == 0)
		frame += 1;
	else if (x % 2 == 1 && y % 2 == 0)
		frame += 2;
	else if (x % 2 == 0 && y % 2 == 1)
		frame += 3;
	else
		frame += 4;
	if (frame % 4 == 0)
		return (map->sprites.floor_1);
	else if (frame % 4 == 1)
		return (map->sprites.floor_2);
	else if (frame % 4 == 2)
		return (map->sprites.floor_3);
	return (map->sprites.floor_4);
}*/

xpm_t	*floor_select(t_map *map, size_t x, size_t y, size_t frame)
{
	int	a;

	a = rand();
	(void)frame;
	(void)x;
	(void)y;
	if (a % 4 == 0)
		return (map->sprites.floor_1);
	else if (a % 4 == 1)
		return (map->sprites.floor_2);
	else if (a % 4 == 2)
		return (map->sprites.floor_3);
	return (map->sprites.floor_4);
}

xpm_t	*flower_select(t_map *map, size_t x, size_t y, size_t frame)
{
	if (x % 2 == 0 && y % 2 == 0)
		frame += 1;
	else if (x % 2 == 1 && y % 2 == 0)
		frame += 2;
	else if (x % 2 == 0 && y % 2 == 1)
		frame += 3;
	else
		frame += 4;
	if (frame % 4 == 0)
		return (map->sprites.floor_1);
	else if (frame % 4 == 1)
		return (map->sprites.floor_2);
	else if (frame % 4 == 2)
		return (map->sprites.floor_3);
	return (map->sprites.floor_4);
}

void	regenerate_water(t_map *map)
{
	size_t	i;
	xpm_t	*tx;

	i = 0;
	while (i < map->n_images)
	{
		if (map->mtrx[i].c == '0')
		{
			tx = texture(map, map->mtrx[i].x, map->mtrx[i].y);
			mlx_draw_texture(map->mtrx[i].img, &tx->texture, 0, 0);
		}
		i++;
	}
}

void	regenerate_enemies(t_map *map)
{
	size_t	i;
	xpm_t	*tx;

	i = 0;
	while (i < map->n_extra)
	{
		if (map->mx_add[i].c == 'V')
		{
			tx = enemy_selector(map);
			mlx_draw_texture(map->mx_add[i].img, &tx->texture, 0, 0);
		}
		i++;
	}
}

void	change_flowers(t_map *map)
{
	size_t	i;
	xpm_t	*tx;

	i = 0;
	while (i < map->n_images)
	{
		if (map->mtrx[i].c == 'C')
		{
			tx = texture(map, map->mtrx[i].x, map->mtrx[i].y);
			mlx_draw_texture(map->mtrx[i].img, &tx->texture, 0, 0);
		}
		i++;
	}
}

xpm_t	*inner_walls_select(t_map *map, size_t x, size_t y)
{
	char	**s;

	s = map->str;
	if (s[y - 1][x] != '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_island);
	else if (s[y - 1][x] == '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_end_b);
	else if (s[y - 1][x] != '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_end_to);
	else if (s[y - 1][x] != '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_end_l);
	else if (s[y - 1][x] != '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_end_r);
	else if (s[y - 1][x] == '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_corridor_t_b);
	else if (s[y - 1][x] != '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_corridor_r_l);
	else if (s[y - 1][x] == '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_corner_b_r);
	else if (s[y - 1][x] == '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_corner_b_l);
	else if (s[y - 1][x] != '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_corner_t_l);
	else if (s[y - 1][x] != '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_corner_t_r);
	else if (s[y - 1][x] == '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_to);
	else if (s[y - 1][x] != '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_b);
	else if (s[y - 1][x] == '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] == '1')
		return (map->sprites.grass.grass_r);
	else if (s[y - 1][x] == '1' && s[y + 1][x] == '1'
		&& s[y][x + 1] == '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass_l);
	else if (s[y - 1][x] != '1' && s[y + 1][x] != '1'
		&& s[y][x + 1] != '1' && s[y][x - 1] != '1')
		return (map->sprites.grass.grass);
	return (map->sprites.grass.grass);
}

xpm_t	*walls_select(t_map *map, size_t x, size_t y)
{
	if (x == 0 && y == 0 && map->str[y + 1][x + 1] != '1')
		return (map->sprites.grass.corner_t_l);
	else if (x == 0 && y == map->n_lines - 1 && map->str[y - 1][x + 1] != '1')
		return (map->sprites.grass.corner_b_l);
	else if (x == map->n_chars - 1 && y == 0 && map->str[y + 1][x - 1] != '1')
		return (map->sprites.grass.corner_t_r);
	else if (x == map->n_chars - 1 && y == map->n_lines - 1
		&& map->str[y - 1][x + 1] != '1')
		return (map->sprites.grass.corner_b_r);
	else if (x == 0 && map->str[y][x + 1] != '1')
		return (map->sprites.grass.grass_r);
	else if (y == 0 && map->str[y + 1][x] != '1')
		return (map->sprites.grass.grass_to);
	else if (x == map->n_chars - 1 && map->str[y][x - 1] != '1')
		return (map->sprites.grass.grass_l);
	else if (y == map->n_lines - 1 && map->str[y - 1][x] != '1')
		return (map->sprites.grass.grass_b);
	else if (x == 0 || y == 0 || x == map->n_chars - 1
		|| y == map->n_lines - 1)
		return (map->sprites.grass.grass);
	//return (map->sprites.grass.grass);
	return (inner_walls_select(map, x, y));
}

xpm_t	*texture(t_map *map, size_t x, size_t y)
{
	if (map->mtrx[y * map->n_chars + x].c == '1')
		return (walls_select(map, x, y));
	else
		return (floor_select(map, x, y, map->anim.frame_water));
	return (0);
}

xpm_t	*enemy_selector(t_map *map)
{
	if (map->anim.frame_enemy == 0)
		return (map->sprites.enemy1);
	else if (map->anim.frame_enemy == 2)
		return (map->sprites.enemy3);
	return (map->sprites.enemy2);
}

xpm_t	*extra_selector(t_map *map, char c)
{
	if (c == 'P')
		return (map->sprites.player);
	else if (c == 'V')
		return (enemy_selector(map));
	else if (c == 'E')
		return (map->sprites.exit);
	else if (c == 'C')
		return (map->sprites.collect_1);
	return (map->sprites.collect_1);
}
