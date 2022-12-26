/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/26 21:33:23 by omontero         ###   ########.fr       */
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
	s->floor_2 = mlx_load_xpm42("pixelart/water.xpm42");
	s->floor_3 = mlx_load_xpm42("pixelart/water.xpm42");
	s->floor_4 = mlx_load_xpm42("pixelart/water.xpm42");
	s->collect_1 = mlx_load_xpm42("pixelart/flower_mid.xpm42");
	s->collect_2 = mlx_load_xpm42("pixelart/flower_open.xpm42");
	s->exit = mlx_load_xpm42("pixelart/exit_basket.xpm42");
}

void	assign_to_map(t_map *map, char *path)
{
	map->move = 1;
	time(&map->time);
	map->n_extra = 0;
	map->n_extra_count = 0;
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
	map->f_text = ft_strdup("Moves:");
	map->total_frames = 0;
	assign_sprites(&map->sprites);
	if (!map->n_lines)
		map->error = 1;
}

/**
 * @brief Esta funcion lee el mapa
 * 
* @param p argv[1] -> Path al archivo mapa.ber
 * @return t_map El mapa devuelto en forma de estructura.
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
	new_map.structure = (char **)malloc(new_map.n_lines * sizeof(char *));
	while (n_lin < new_map.n_lines && !new_map.error)
	{
		check_line(line, n_lin, &new_map);
		new_map.structure[n_lin] = line;
		line = get_next_line(fd);
		n_lin++;
	}
	close(fd);
	return (new_map);
}

void	start(t_map *map, char *p)
{
	*map = read_map(p);
	check_player_coords(map);
	check_exit_and_coin(map);
	check_enemies(map);
	map->n_total = map->n_images + map->coins.n_coins + map->n_enemies + 3;
	map->image = (mlx_image_t **)malloc((map->n_total) * sizeof(mlx_image_t *));
	map->image_old = (mlx_image_t **)malloc((map->n_total)
			* sizeof(mlx_image_t *));
}
