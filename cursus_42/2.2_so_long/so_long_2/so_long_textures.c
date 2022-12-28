/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/27 20:20:44 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

xpm_t	*floor_select(t_map *map, size_t x, size_t y)
{
	if (x % 2 == 0 && y % 2 == 0)
		return (map->sprites.floor_1);
	else if (x % 2 == 1 && y % 2 == 0)
		return (map->sprites.floor_2);
	else if (x % 2 == 0 && y % 2 == 1)
		return (map->sprites.floor_3);
	else
		return (map->sprites.floor_4);
}

xpm_t	*walls_select(t_map *map, size_t x, size_t y)
{
	if (x == 0 && y == 0)
		return (map->sprites.corner_t_l);
	else if (x == 0 && y == map->n_lines - 1)
		return (map->sprites.corner_b_l);
	else if (x == map->n_chars - 1 && y == 0)
		return (map->sprites.corner_t_r);
	else if (x == map->n_chars - 1 && y == map->n_lines - 1)
		return (map->sprites.corner_b_r);
	else if (x == 0)
		return (map->sprites.wall_l);
	else if (y == 0)
		return (map->sprites.wall_t);
	else if (x == map->n_chars - 1)
		return (map->sprites.wall_r);
	else if (y == map->n_lines - 1)
		return (map->sprites.wall_b);
	return (map->sprites.wall);
}

xpm_t	*texture(t_map *map, size_t x, size_t y)
{
	if (map->mtrx[y * map->n_chars + x].c == '1')
		return (walls_select(map, x, y));
	else if (map->mtrx[y * map->n_chars + x].c == 'E')
		return (map->sprites.exit);
	else
		return (floor_select(map, x, y));
	return (0);
}

xpm_t	*extra_selector(t_map *map, char c, size_t x, size_t y)
{
	if (c == 'P')
		return (map->sprites.player);
	else if (c == 'V')
		return (map->sprites.enemy);
	else if (c == 'C')
	{
		if (x == map->coins.coin_t_x && y == map->coins.coin_t_y)
		{
			if (map->anim.frame_chest == 0)
				return (map->sprites.collect_1);
			else if (map->anim.frame_chest == 2)
				return (map->sprites.collect_1);
			else if (map->anim.frame_chest == 4)
				return (map->sprites.collect_2);
			else if (map->anim.frame_chest == 6)
				return (map->sprites.collect_2);
			else
				return (map->sprites.collect_2);
		}
	}
	return (mlx_load_xpm42("pixelart/flower_mid.xpm42"));
}
