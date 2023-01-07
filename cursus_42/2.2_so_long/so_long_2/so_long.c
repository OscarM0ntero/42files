/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/07 21:32:50 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& map->move)
		move(1, map);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& map->move)
		move(2, map);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& map->move)
		move(3, map);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& map->move)
		move(4, map);
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		|| ((keydata.key == MLX_KEY_ENTER && keydata.action == MLX_PRESS)
			&& (map->map_finished || map->game_over)))
		mlx_close_window(map->mlx);
}

void	print_counters(t_map *map)
{
	char	*c;
	char	*d;
	char	*e;
	char	*tmp;

	c = new_itoa(map->mv_count);
	tmp = c;
	c = ft_strjoin(" Moves: ", c);
	free (tmp);
	d = new_itoa(map->coins.c_count);
	tmp = d;
	d = ft_strjoin("  Flowers: ", d);
	free (tmp);
	tmp = d;
	d = ft_strjoin(d, "/");
	free (tmp);
	e = new_itoa(map->coins.n_coins);
	tmp = e;
	d = ft_strjoin(d, e);
	free (tmp);
	tmp = c;
	c = ft_strjoin(c, d);
	free (tmp);
	mlx_delete_image(map->mlx, map->mtrx[0].img);
	map->mtrx[0].img = mlx_put_string(map->mlx, c, 0, 0);
	free(c);
}

mlx_texture_t	*fade_selector(t_map *map)
{
	if (!map->anim.frame_fade)
		return (&map->sprites.fade1->texture);
	else if (map->anim.frame_fade == 1)
		return (&map->sprites.fade2->texture);
	else if (map->anim.frame_fade == 2)
		return (&map->sprites.fade3->texture);
	else if (map->anim.frame_fade == 3)
		return (&map->sprites.fade4->texture);
	return (&map->sprites.fade5->texture);
	map->anim.frame_enemy++;
}

void	fade_black(t_map *map)
{
	mlx_image_t		*b_screen;
	size_t			i;
	size_t			j;
	mlx_texture_t	*tx;

	tx = fade_selector(map);
	b_screen = mlx_new_image(map->mlx, map->n_chars * IMG_W,
			map->n_lines * IMG_H);
	memset(b_screen->pixels, 255, b_screen->width * b_screen->height
		* sizeof(int));
	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			mlx_draw_texture(b_screen, tx, j * IMG_W, i * IMG_H);
		}
	}
	mlx_image_to_window(map->mlx, b_screen, 0, 0);
	map->black[map->anim.frame_fade] = b_screen;
}

void	end_string(t_map *map)
{
	if (map->anim.frame_fade == 5 && map->map_finished)
		map->end = mlx_put_string(map->mlx, "YOU WON!", map->n_chars
				* (IMG_W / 2) - (IMG_W / 2), map->n_lines
				* (IMG_H / 2) - (IMG_H / 2));
	else if (map->anim.frame_fade == 5 && map->game_over)
	{
		map->end = mlx_put_string(map->mlx, "YOU DIED...", map->n_chars
				* (IMG_W / 2) - (IMG_W / 2), map->n_lines
				* (IMG_H / 2) - (IMG_H / 2));
	}
}

void	timer(void *param)
{
	t_map	*map;

	map = param;
	if (map->time && map->anim.frame_fade != 6)
	{
		print_map(map);
		print_counters(map);
		usleep(10000);
		map->time += 1;
	}
	if ((map->map_finished || map->game_over) && map->anim.frame_fade < 5
		&& map->time % 5 == 0)
	{
		map->move = 0;
		fade_black(map);
		map->anim.frame_fade++;
	}
	if (map->anim.frame_fade == 5)
		end_string(map);
	if (map->anim.frame_fade == 5)
		map->anim.frame_fade++;
}

void	animhook(void *param)
{
	t_map	*map;

	map = param;
	if (map->time % 30 == 0)
	{
		map->anim.frame_water++;
		regenerate_water(map);
		if (map->time % 100 == 0)
			map->anim.frame_water = 0;
	}
	if (map->time % 15 == 0)
	{
		regenerate_enemies(map);
		map->anim.frame_enemy++;
		if (map->anim.frame_enemy == 4)
			map->anim.frame_enemy = 0;
	}
}

/**
 * @brief Generate the background images
 * 
 * @param map Map pointer
 * @param x X position of the chunk we are generating the image of
 * @param y Y pos
 */
void	generate_image(t_map *map, int32_t x, int32_t y)
{
	xpm_t			*tx;

	tx = texture(map, x, y);
	map->mtrx[(y * map->n_chars) + x].img
		= mlx_texture_to_image(map->mlx, &tx->texture);
	if (!map->img_assigned)
		map->img_assigned = 1;
}

void	delete_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->n_images)
	{
		mlx_delete_image(map->mlx, map->mtrx[i].img);
		i++;
	}
	i = 0;
	while (i < map->n_extra)
	{
		mlx_delete_image(map->mlx, map->mx_add[i].img);
		i++;
	}
	mlx_delete_image(map->mlx, map->black[0]);
	mlx_delete_image(map->mlx, map->black[1]);
	mlx_delete_image(map->mlx, map->black[2]);
	mlx_delete_image(map->mlx, map->black[3]);
	mlx_delete_image(map->mlx, map->black[4]);
	mlx_delete_image(map->mlx, map->end);
	free(map->mtrx);
	free(map->mx_add);
	free(map->path);
}

void	create_extra_images(t_map *map)
{
	size_t		i;
	xpm_t		*tx;

	i = -1;
	while (++i < map->n_extra)
	{
		tx = extra_selector(map, map->mx_add[i].c);
		map->mx_add[i].img = mlx_texture_to_image(map->mlx, &tx->texture);
	}
}

void	map_to_window(t_map *map)
{
	size_t			i;

	i = -1;
	while (++i < map->n_images)
	{
		mlx_image_to_window(map->mlx, map->mtrx[i].img, map->mtrx[i].x * IMG_W,
			map->mtrx[i].y * IMG_H);
	}
	i = map->n_extra + 1;
	while (--i)
	{
		mlx_image_to_window(map->mlx, map->mx_add[i - 1].img, map->mx_add[i - 1].x
			* IMG_W, map->mx_add[i - 1].y * IMG_H);
	}
}

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			generate_image(map, j, i);
		}
	}
	create_extra_images(map);
	map_to_window(map);
	map->mtrx[0].img = mlx_put_string(map->mlx, "Moves:", 0, 0);
	map->total_frames++;
}

//	Adaptar textura invisible, obligar a pillar moneda, ventana win and lose
//	Progrmar sprites con condiciones
//	IMPORTANTE: ADMINISTRAR IMAGENES EXTRA AL FINAL DEL ARRAY
void	show_leaks(void)
{
	system("leaks -q so_long");
}

void	delete_grass_tx(t_sprites *s)
{
	mlx_delete_xpm42(s->grass.corner_b_l);
	mlx_delete_xpm42(s->grass.corner_b_r);
	mlx_delete_xpm42(s->grass.corner_t_l);
	mlx_delete_xpm42(s->grass.corner_t_r);
	mlx_delete_xpm42(s->grass.grass_b);
	mlx_delete_xpm42(s->grass.grass_l);
	mlx_delete_xpm42(s->grass.grass_r);
	mlx_delete_xpm42(s->grass.grass_to);
	mlx_delete_xpm42(s->grass.grass_corner_b_l);
	mlx_delete_xpm42(s->grass.grass_corner_b_r);
	mlx_delete_xpm42(s->grass.grass_corner_t_l);
	mlx_delete_xpm42(s->grass.grass_corner_t_r);
	mlx_delete_xpm42(s->grass.grass_corridor_r_l);
	mlx_delete_xpm42(s->grass.grass_corridor_t_b);
	mlx_delete_xpm42(s->grass.grass_end_b);
	mlx_delete_xpm42(s->grass.grass_end_l);
	mlx_delete_xpm42(s->grass.grass_end_r);
	mlx_delete_xpm42(s->grass.grass_end_to);
	mlx_delete_xpm42(s->grass.grass_island);
}

void	delete_txs(t_map *map)
{
	t_sprites	*s;

	s = &map->sprites;
	mlx_delete_xpm42(s->player);
	mlx_delete_xpm42(s->player_back);
	mlx_delete_xpm42(s->enemy1);
	mlx_delete_xpm42(s->enemy2);
	mlx_delete_xpm42(s->enemy3);
	mlx_delete_xpm42(s->floor_1);
	mlx_delete_xpm42(s->floor_2);
	mlx_delete_xpm42(s->floor_3);
	mlx_delete_xpm42(s->floor_4);
	mlx_delete_xpm42(s->collect_1);
	mlx_delete_xpm42(s->collect_2);
	mlx_delete_xpm42(s->exit);
	mlx_delete_xpm42(s->fade1);
	mlx_delete_xpm42(s->fade2);
	mlx_delete_xpm42(s->fade3);
	mlx_delete_xpm42(s->fade4);
	mlx_delete_xpm42(s->fade5);
	mlx_delete_xpm42(s->grass.grass);
	delete_grass_tx(s);
}

int	main(int argc, char **argv)
{
	t_map	m;

	if (argc != 2)
		return (printf("Error: No map introduced.\n"), 1);
	start(&m, argv[1]);
	if (error_handler(m.error))
		exit(EXIT_FAILURE);
	m.mlx = mlx_init(m.n_chars * IMG_W, m.n_lines * IMG_H, "So_Long", true);
	if (!m.mlx)
		exit(EXIT_FAILURE);
	if (!m.error)
		generate_map(&m);
	mlx_key_hook(m.mlx, &keyhook, &m);
	mlx_loop_hook(m.mlx, &animhook, &m);
	mlx_loop_hook(m.mlx, &timer, &m);
	mlx_loop(m.mlx);
	mlx_terminate(m.mlx);
	delete_txs(&m);
	delete_map(&m);
	show_leaks();
	return (EXIT_SUCCESS);
}

/*
int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	map;

	map = read_map(argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, (WIDTH - IMG_WIDTH) / 2, (HEIGHT - IMG_HEIGHT) / 2);
	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_put_pixel(g_img, 10, 10, 0x00FF0000);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */

/*
int	main(int argc, char **argv)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_new_w
}
*/