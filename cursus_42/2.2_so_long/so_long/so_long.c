/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/27 03:13:27 by omontero         ###   ########.fr       */
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

void	animhook(void *param)
{
	t_map	*map;

	map = param;
	if (map->coins.coin_taked && map->anim.frame_chest < 11 && map->anim.frame_chest % 2 == 0)
	{
		print_map(map);
		usleep (200000);
	}
	if (map->coins.coin_taked && map->anim.frame_chest++ == 11)
	{
		map->anim.frame_chest = 0;
		map->coins.coin_taked = 0;
		map->structure[map->coins.coin_t_y][map->coins.coin_t_x] = '0';
		print_map(map);
		map->coins.c_count++;
		map->coins.coin_t_x = 0;
		map->coins.coin_t_y = 0;
		map->move = 1;
	}
	//	???
	/*if (map->time != time(NULL))
	{
		print_map(map);
		sleep(1);
		usleep(20000);
		time(&map->time);
	}*/
	if (clock() > map->clock + 160000)
	{
		print_map(map);
		map->clock = clock();
		//usleep(20000);
		//time(&map->time);
	}
}

xpm_t	*temp_flor_select(t_map *map, size_t x, size_t y)
{
	if (x < 1 || y < 1)
		return (map->sprites.floor_1);
	if (x % 2 == 0 && y % 2 == 0)
		return (map->sprites.floor_2);
	else if (x % 2 == 1 && y % 2 == 0)
		return (map->sprites.floor_3);
	else if (x % 2 == 0 && y % 2 == 1)
		return (map->sprites.floor_4);
	else
		return (map->sprites.floor_1);
}

xpm_t	*exterior_select(t_map *map, size_t x, size_t y)
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

xpm_t	*texture(char c, size_t x, size_t y, t_map *map)
{
	(void)map;
	if (c == '1')
		return (exterior_select(map, x, y));
	else if (c == 'E')
		return (map->sprites.exit);
	else if (map->structure[y][x] == 'P' && !map->move && map->map_finished)
		return (map->sprites.exit);
	else if (x > 0 && y > 0)
		return (temp_flor_select(map, x, y));
	else
		return (map->sprites.wall);
	return (0);
}

void	generate_image(t_map *map, int32_t x, int32_t y, char c)
{
	xpm_t			*tx;
	mlx_image_t		*g_img;

	g_img = mlx_new_image(map->mlx, IMG_W, IMG_H);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	tx = texture(c, x, y, map);
	g_img = mlx_texture_to_image(map->mlx, &tx->texture);
	//mlx_delete_xpm42(tx);
	//mlx_draw_texture(g_img, tx, 0, 0);
	//mlx_delete_texture(tx);
	//mlx_image_to_window(map->mlx, g_img, x * IMG_W, y * IMG_H);
	if (!map->img_assigned)
		map->img_assigned = 1;
	map->image[(y * map->n_chars) + x] = g_img;
}

void	delete_map(mlx_t *mlx, mlx_image_t **image, size_t size, size_t *extra)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		mlx_delete_image(mlx, image[i]);
		i++;
	}
	*extra = 0;
}

xpm_t	*extra_selector(t_map *map, char c, size_t x, size_t y)
{
	if (c == 'P')
		return (map->sprites.player);
	else if (c == 'V')
		return (map->sprites.enemy);
	else if (c == 'C')
	{
		/*if (x == map->coins.coin_t_x && y == map->coins.coin_t_y)
		{
			if (map->anim.frame_chest == 0)
				return (mlx_load_png("sprites/c_c.png"));
			else if (map->anim.frame_chest == 2)
				return (mlx_load_png("sprites/c_h1.png"));
			else if (map->anim.frame_chest == 4)
				return (mlx_load_png("sprites/c_h2.png"));
			else if (map->anim.frame_chest == 6)
				return (mlx_load_png("sprites/c_o.png"));
			else
				return (mlx_load_png("sprites/coins.png"));
		}*/
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

void	create_extra_image(t_map *map, size_t x, size_t y)
{
	xpm_t			*tx;
	mlx_image_t		*img;
	char			c;
	char			*s;

	c = map->structure[y][x];
	img = mlx_new_image(map->mlx, IMG_W, IMG_H);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	if (!x && !y)
		img = mlx_put_string(map->mlx, map->f_text, 0, 0);
	else if (x == 1 && !y)
	{
		s = new_itoa((int)map->mv_count);
		img = mlx_put_string(map->mlx, s, 0, 0);
		free (s);
	}
	else
	{
		tx = extra_selector(map, c, x, y);
		img = mlx_texture_to_image(map->mlx, &tx->texture);
		//mlx_delete_xpm42(tx);
		//mlx_draw_texture(img, tx, 0, 0);
		//mlx_delete_texture(tx);
	}
	map->image[map->n_images + map->n_extra] = img;
	map->n_extra++;
}

void	map_to_window(t_map *map)
{
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			mlx_image_to_window(map->mlx, map->image[(i * map->n_chars) + j],
				j * IMG_W, i * IMG_H);
			if (map->structure[i][j] == 'P' || map->structure[i][j] == 'V'
				|| map->structure[i][j] == 'C' || (!j && !i) || (j == 1 && !i))
			{
				mlx_image_to_window(map->mlx,
					map->image[(map->n_images + map->n_extra_count)],
					j * IMG_W, i * IMG_H);
				map->n_extra_count++;
			}
		}
	}
	map->n_extra_count = 0;
}

void	assign_old_map(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->n_total)
	{
		map->image_old[i] = map->image[i];
	}
}

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	if (map->img_assigned)
	{
		delete_map(map->mlx, map->image_old, map->n_total, &map->n_extra);
	}
	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			generate_image(map, j, i, map->structure[i][j]);
			if (map->structure[i][j] == 'P' || map->structure[i][j] == 'V'
				|| map->structure[i][j] == 'C' || (!j && !i) || (j == 1 && !i))
				create_extra_image(map, j, i);
		}
	}
	map_to_window(map);
	assign_old_map(map);
	map->total_frames++;
}

//	Adaptar textura invisible, obligar a pillar moneda, ventana win and lose
//	Progrmar sprites con condiciones
//	IMPORTANTE: ADMINISTRAR IMAGENES EXTRA AL FINAL DEL ARRAY
void	show_leaks(void)
{
	system("leaks -q so_long");
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
		print_map(&m);
	mlx_key_hook(m.mlx, &keyhook, &m);
	mlx_loop_hook(m.mlx, &animhook, &m);
	mlx_loop(m.mlx);
	delete_map(m.mlx, m.image_old, m.n_total, &m.n_extra);
	mlx_terminate(m.mlx);
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