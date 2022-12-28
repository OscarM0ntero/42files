/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/28 17:13:44 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_sprites(t_sprites *s)
{
	s->player = mlx_load_xpm42("pixelart/duck.xpm42");
	s->enemy = mlx_load_xpm42("pixelart/shark.xpm42");
	s->corner_t_r = mlx_load_xpm42("pixelart/corner_top_right.xpm42");
	s->corner_t_l = mlx_load_xpm42("pixelart/corner_top_left.xpm42");
	s->corner_b_r = mlx_load_xpm42("pixelart/corner_bot_right.xpm42");
	s->corner_b_l = mlx_load_xpm42("pixelart/corner_bot_left.xpm42");
	s->wall_t = mlx_load_xpm42("pixelart/grass_top.xpm42");
	s->wall_b = mlx_load_xpm42("pixelart/grass_bot.xpm42");
	s->wall_r = mlx_load_xpm42("pixelart/grass_right.xpm42");
	s->wall_l = mlx_load_xpm42("pixelart/grass_left.xpm42");
	s->wall = mlx_load_xpm42("pixelart/grass.xpm42");
	s->floor_1 = mlx_load_xpm42("pixelart/water.xpm42");
	s->floor_2 = mlx_load_xpm42("pixelart/water2.xpm42");
	s->floor_3 = mlx_load_xpm42("pixelart/water3.xpm42");
	s->floor_4 = mlx_load_xpm42("pixelart/water4.xpm42");
	s->collect_1 = mlx_load_xpm42("pixelart/flower_mid.xpm42");
	s->collect_2 = mlx_load_xpm42("pixelart/flower_open.xpm42");
	s->exit = mlx_load_xpm42("pixelart/exit_basket.xpm42");
}

/**
 * @brief Assigns default values to map
 * @param map map pointer
 * @param p path to .ber file
 */
void	assign_to_map(t_map *map, char *path)
{
	map->clock = clock();
	map->move = 1;
	time(&map->time);
	map->n_extra = 0;
	map->img_assigned = 0;
	map->anim.frame_chest = 0;
	map->anim.frame_enemy = 0;
	map->anim.frame_player = 0;
	map->error = 0;
	map->n_chars = 0;
	map->path = ft_strdup(path);
	map->n_lines = count_lines(map->path);
	map->coins.n_coins = 0;
	map->coins.coin_taked = 0;
	map->coins.coin_t_x = 0;
	map->coins.coin_t_y = 0;
	map->n_enemies = 0;
	map->coins.c_count = 0;
	map->game_over = 0;
	map->map_finished = 0;
	map->mv_count = 0;
	map->total_frames = 0;
	assign_sprites(&map->sprites);
	if (!map->n_lines)
		map->error = 1;
}

/**
 * @brief Reads a .ber file and saves the map on a strings array
 * 
* @param p path to .ber file
 * @return New map created
 */
t_map	read_map(char *p)
{
	t_map	new_map;
	int		fd;
	char	*line;
	size_t	n_lin;

	n_lin = 0;
	assign_to_map(&new_map, p);
	if (new_map.error)
		return (new_map);
	fd = open(new_map.path, O_RDONLY);
	line = get_next_line(fd);
	new_map.n_chars = ft_strlen(line);
	new_map.n_images = new_map.n_lines * new_map.n_chars;
	new_map.str = (char **)malloc(new_map.n_lines * sizeof(char *));
	while (n_lin < new_map.n_lines && !new_map.error)
	{
		check_line(line, n_lin, &new_map);
		new_map.str[n_lin] = line;
		line = get_next_line(fd);
		n_lin++;
	}
	close(fd);
	return (new_map);
}

/**
 * @brief Assigns the values to the matrix, 0 if its an object
 * 
 * @param map Pointer to the map
 */
void	assign_mtrx(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = -1;
	count = 0;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			/*if ((!i && !j) || (!i && j == 1))
			{
				map->mx_add[count].c = 'T';
				map->mx_add[count].x = j;
				map->mx_add[count].y = i;
			}*/
			if (map->str[i][j] == ('P') || map->str[i][j] == ('C')
				|| map->str[i][j] == ('V'))
			{
				map->mtrx[i * map->n_chars + j].c = '0';
				map->mx_add[count].c = map->str[i][j];
				map->mx_add[count].x = j;
				map->mx_add[count].y = i;
				count++;
			}
			else
				map->mtrx[i * map->n_chars + j].c = map->str[i][j];
			map->mtrx[i * map->n_chars + j].x = j;
			map->mtrx[i * map->n_chars + j].y = i;
		}
	}
}

/**
 * @brief Starts the assignation of values, reading the map and 
 * checking the coords of the props, assigning the size of the arrays
 * 
 * @param map mapa
 * @param p path of the .ber file
 */
void	start(t_map *map, char *p)
{
	*map = read_map(p);
	check_player_coords(map);
	check_exit_and_coin(map);
	check_enemies(map);
	map->n_extra = map->coins.n_coins + map->n_enemies + 1;	//2 if added counter
	map->n_total = map->n_images + map->n_extra;
	map->mtrx = (t_matrix_sq *)malloc(map->n_images * sizeof(t_matrix_sq));
	map->mx_add = (t_matrix_sq *)malloc((map->n_extra * sizeof(t_matrix_sq)));
	assign_mtrx(map);
}
