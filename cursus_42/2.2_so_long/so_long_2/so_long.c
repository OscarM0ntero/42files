/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/29 18:21:22 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Continuar pensando el hacer 1 sola imagen y tratar las cosas como objetos con prioridades
	(Arrays de collectables y enemigos con propiedades y coordenadas)
*/

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

void	timer(void *param)
{
	t_map	*map;

	map = param;
	if (map->time)
	{
		print_map(map);
		printf("Reloj: %lu\n", map->time);
		usleep(10000);
		map->time += 1;
	}
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
		map->str[map->coins.coin_t_y][map->coins.coin_t_x] = '0';
		print_map(map);
		map->coins.c_count++;
		map->coins.coin_t_x = 0;
		map->coins.coin_t_y = 0;
		map->move = 1;
	}
	if (map->time % 33 == 0)
	{
		map->anim.frame_water++;
		regenerate_water(map);
		if (map->time % 132 == 0)
			map->anim.frame_water = 0;
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
}

void	create_extra_images(t_map *map)
{
	size_t		i;
	xpm_t		*tx;

	i = -1;
	while (++i < map->n_extra)
	{
		tx = extra_selector(map, map->mx_add[i].c, map->mx_add[i].x,
				map->mx_add[i].y);
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
	i = -1;
	while (++i < map->n_extra)
	{
		mlx_image_to_window(map->mlx, map->mx_add[i].img, map->mx_add[i].x
			* IMG_W, map->mx_add[i].y * IMG_H);
	}
}

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;
	char	*c;

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
	c = new_itoa(map->mv_count);
	map->mtrx[0].img = mlx_put_string(map->mlx, c, IMG_W, 0);
	free(c);
	map->total_frames++;
}

//	Adaptar textura invisible, obligar a pillar moneda, ventana win and lose
//	Progrmar sprites con condiciones
//	IMPORTANTE: ADMINISTRAR IMAGENES EXTRA AL FINAL DEL ARRAY
void	show_leaks(void)
{
	system("leaks -q so_long");
}

void	delete_txs(t_map *map)
{
	mlx_delete_xpm42(map->sprites.player);
	mlx_delete_xpm42(map->sprites.enemy);
	mlx_delete_xpm42(map->sprites.exit);
	mlx_delete_xpm42(map->sprites.collect_1);
	mlx_delete_xpm42(map->sprites.collect_2);
	mlx_delete_xpm42(map->sprites.corner_b_l);
	mlx_delete_xpm42(map->sprites.corner_b_r);
	mlx_delete_xpm42(map->sprites.corner_t_l);
	mlx_delete_xpm42(map->sprites.corner_t_r);
	mlx_delete_xpm42(map->sprites.wall);
	mlx_delete_xpm42(map->sprites.wall_b);
	mlx_delete_xpm42(map->sprites.wall_l);
	mlx_delete_xpm42(map->sprites.wall_r);
	mlx_delete_xpm42(map->sprites.wall_t);
	mlx_delete_xpm42(map->sprites.floor_1);
	mlx_delete_xpm42(map->sprites.floor_2);
	mlx_delete_xpm42(map->sprites.floor_3);
	mlx_delete_xpm42(map->sprites.floor_4);
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
	delete_map(&m);
	mlx_terminate(m.mlx);
	delete_txs(&m);
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