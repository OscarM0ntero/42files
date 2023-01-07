/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/07 21:27:37 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_grass(t_sprites *s)
{
	s->grass.corner_b_l = mlx_load_xpm42("pixelart/corner_b_l.xpm42");
	s->grass.corner_b_r = mlx_load_xpm42("pixelart/corner_b_r.xpm42");
	s->grass.corner_t_l = mlx_load_xpm42("pixelart/corner_t_l.xpm42");
	s->grass.corner_t_r = mlx_load_xpm42("pixelart/corner_t_r.xpm42");
	s->grass.grass_b = mlx_load_xpm42("pixelart/grass_b.xpm42");
	s->grass.grass_l = mlx_load_xpm42("pixelart/grass_l.xpm42");
	s->grass.grass_r = mlx_load_xpm42("pixelart/grass_r.xpm42");
	s->grass.grass_to = mlx_load_xpm42("pixelart/grass_t.xpm42");
	s->grass.grass_corner_b_l
		= mlx_load_xpm42("pixelart/grass_corner_b_l.xpm42");
	s->grass.grass_corner_b_r
		= mlx_load_xpm42("pixelart/grass_corner_b_r.xpm42");
	s->grass.grass_corner_t_l
		= mlx_load_xpm42("pixelart/grass_corner_t_l.xpm42");
	s->grass.grass_corner_t_r
		= mlx_load_xpm42("pixelart/grass_corner_t_r.xpm42");
	s->grass.grass_corridor_r_l
		= mlx_load_xpm42("pixelart/grass_corridor_r_l.xpm42");
	s->grass.grass_corridor_t_b
		= mlx_load_xpm42("pixelart/grass_corridor_t_b.xpm42");
	s->grass.grass_end_b = mlx_load_xpm42("pixelart/grass_end_b.xpm42");
	s->grass.grass_end_l = mlx_load_xpm42("pixelart/grass_end_l.xpm42");
	s->grass.grass_end_r = mlx_load_xpm42("pixelart/grass_end_r.xpm42");
	s->grass.grass_end_to = mlx_load_xpm42("pixelart/grass_end_t.xpm42");
	s->grass.grass_island = mlx_load_xpm42("pixelart/grass_island.xpm42");
}

void	assign_sprites(t_sprites *s)
{
	s->player = mlx_load_xpm42("pixelart/duck.xpm42");
	s->player_back = mlx_load_xpm42("pixelart/duck_back.xpm42");
	s->enemy1 = mlx_load_xpm42("pixelart/shark1.xpm42");
	s->enemy2 = mlx_load_xpm42("pixelart/shark2.xpm42");
	s->enemy3 = mlx_load_xpm42("pixelart/shark3.xpm42");
	s->floor_1 = mlx_load_xpm42("pixelart/water1.xpm42");
	s->floor_2 = mlx_load_xpm42("pixelart/water2.xpm42");
	s->floor_3 = mlx_load_xpm42("pixelart/water3.xpm42");
	s->floor_4 = mlx_load_xpm42("pixelart/water4.xpm42");
	s->collect_1 = mlx_load_xpm42("pixelart/flower_mid.xpm42");
	s->collect_2 = mlx_load_xpm42("pixelart/flower_open.xpm42");
	s->exit = mlx_load_xpm42("pixelart/basket.xpm42");
	s->fade1 = mlx_load_xpm42("pixelart/fade1.xpm42");
	s->fade2 = mlx_load_xpm42("pixelart/fade2.xpm42");
	s->fade3 = mlx_load_xpm42("pixelart/fade3.xpm42");
	s->fade4 = mlx_load_xpm42("pixelart/fade4.xpm42");
	s->fade5 = mlx_load_xpm42("pixelart/fade5.xpm42");
	s->grass.grass = mlx_load_xpm42("pixelart/grass.xpm42");
	assign_grass(s);
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
	map->time *= 100;
	map->n_extra = 0;
	map->img_assigned = 0;
	map->anim.frame_flower = 0;
	map->anim.frame_enemy = 0;
	map->anim.frame_player = 0;
	map->anim.frame_fade = 0;
	map->error = 0;
	map->n_chars = 0;
	map->path = ft_strdup(path);
	map->n_lines = count_lines(map->path);
	map->coins.n_coins = 0;
	map->n_enemies = 0;
	map->coins.c_count = 0;
	map->game_over = 0;
	map->map_finished = 0;
	map->mv_count = 0;
	map->total_frames = 0;
	map->anim.frame_water = 0;
	map->anim.frame_enemy = 0;
	assign_sprites(&map->sprites);
	map->p_look = 1;
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
	if (!new_map.n_lines)
		new_map.error = 1;
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

void	found_c(t_map *map, size_t i, size_t j, size_t *c)
{
	map->mtrx[i * map->n_chars + j].c = '0';
	map->mx_add[*c].c = map->str[i][j];
	map->mx_add[*c].x = j;
	map->mx_add[*c].y = i;
	(*c)++;
}

void	found_v(t_map *map, size_t i, size_t j, size_t *c)
{
	map->mtrx[i * map->n_chars + j].c = '0';
	map->mx_add[*c].c = map->str[i][j];
	map->mx_add[*c].x = j;
	map->mx_add[*c].y = i;
	(*c)--;
}

void	found_e(t_map *map, size_t i, size_t j)
{
	map->mtrx[i * map->n_chars + j].c = '0';
	map->mx_add[1].c = map->str[i][j];
	map->mx_add[1].x = j;
	map->mx_add[1].y = i;
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
	size_t	count_rev;

	i = -1;
	count = 2;
	count_rev = map->n_extra - 1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			if (map->str[i][j] == ('C'))
				found_c(map, i, j, &count);
			else if (map->str[i][j] == ('V'))
				found_v(map, i, j, &count_rev);
			else if (map->str[i][j] == ('E'))
				found_e(map, i, j);
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
	if (map->error)
		return ;
	check_player_coords(map);
	if (map->error)
		return ;
	check_exit_and_coin(map);
	check_enemies(map);
	map->n_extra = map->coins.n_coins + map->n_enemies + 2;
	map->n_total = map->n_images + map->n_extra;
	map->mtrx = (t_matrix_sq *)malloc(map->n_images * sizeof(t_matrix_sq));
	map->mx_add = (t_matrix_sq *)malloc((map->n_extra * sizeof(t_matrix_sq)));
	assign_mtrx(map);
	map->mx_add[0].c = 'P';
	map->mtrx[map->p_y * map->n_chars + map->p_x].c = '0';
	map->mx_add[0].x = map->p_x;
	map->mx_add[0].y = map->p_y;
	map->black = (mlx_image_t **)malloc(5 * sizeof(mlx_image_t *));
}
