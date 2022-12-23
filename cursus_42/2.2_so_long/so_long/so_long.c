/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/23 02:26:01 by omontero         ###   ########.fr       */
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
	if (map->coins.coin_taked && map->anim.frame_chest < 13 && map->anim.frame_chest % 2 == 0)
	{
		print_map(map);
		//if (map->anim.frame_chest == 12)
		//	usleep (1000000);
		//else
		//	usleep (300000);
		usleep (1000000);
	}
	if (map->coins.coin_taked && map->anim.frame_chest++ == 13)
	{
		map->anim.frame_chest = 0;
		map->coins.coin_taked = 0;
		map->structure[map->coins.coin_t_y][map->coins.coin_t_x] = '0';
		map->c_count++;
		map->coins.coin_t_x = 0;
		map->coins.coin_t_y = 0;
		map->move = 1;
		print_map(map);
	}
}

mlx_texture_t	*temp_flor_select(size_t x, size_t y)
{
	if (x < 1 || y < 1)
		return (mlx_load_png("sprites/floor1.png"));
	if (x % 2 == 0 && y % 2 == 0)
		return (mlx_load_png("sprites/floor4.png"));
	else if (x % 2 == 1 && y % 2 == 0)
		return (mlx_load_png("sprites/floor1.png"));
	else if (x % 2 == 0 && y % 2 == 1)
		return (mlx_load_png("sprites/floor3.png"));
	else
		return (mlx_load_png("sprites/floor2.png"));
}

mlx_texture_t	*texture(char c, size_t x, size_t y, t_map *map)
{
	(void)map;
	if (c == '1')
		return (mlx_load_png("sprites/wall_brick1.png"));
	else if (c == 'E')
		return (mlx_load_png("sprites/exit_floor.png"));
	else if (map->structure[y][x] == 'P' && !map->move && map->map_finished)
		return (mlx_load_png("sprites/exit_floor.png"));
	else if (x > 0 && y > 0)
		return (temp_flor_select(x, y));
	else
		return (mlx_load_png("sprites/floor5.png"));
	return (0);
}

void	generate_image(t_map *map, int32_t x, int32_t y, char c)
{
	mlx_texture_t	*tx;
	mlx_image_t		*g_img;

	g_img = mlx_new_image(map->mlx, IMG_W, IMG_H);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	tx = texture(c, x, y, map);
	mlx_draw_texture(g_img, tx, 0, 0);
	//mlx_image_to_window(map->mlx, g_img, x * IMG_W, y * IMG_H);
	mlx_delete_texture(tx);
	if (!map->img_assigned)
		map->img_assigned = 1;
	map->image[(y * map->n_chars) + x] = g_img;
}

void	delete_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i< map->n_total)
	{
		mlx_delete_image(map->mlx, map->image[i]);
		i++;
	}
	map->n_extra = 0;
}

mlx_texture_t	*extra_selector(t_map *map, char c, size_t x, size_t y)
{
	mlx_texture_t	*tx;

	if (c == 'P')
		tx = mlx_load_png("sprites/capybara.png");
	else if (c == 'V')
		tx = mlx_load_png("sprites/g1.png");
	else if (c == 'C')
	{
		if (x == map->coins.coin_t_x && y == map->coins.coin_t_y)
		{
			if (map->anim.frame_chest == 0)
				tx = mlx_load_png("sprites/c_c.png");
			else if (map->anim.frame_chest == 2)
				tx = mlx_load_png("sprites/c_h1.png");
			else if (map->anim.frame_chest == 4)
				tx = mlx_load_png("sprites/c_h1.png");
			else if (map->anim.frame_chest == 6)
				tx = mlx_load_png("sprites/c_h2.png");
			else if (map->anim.frame_chest == 8)
				tx = mlx_load_png("sprites/c_o.png");
			else
				tx = mlx_load_png("sprites/coins.png");
		}
		else
			tx = mlx_load_png("sprites/c_c.png");
	}
	return (tx);
}

void	create_extra_image(t_map *map, size_t x, size_t y)
{
	mlx_texture_t	*tx;
	mlx_image_t		*img;
	char			c;

	c = map->structure[y][x];
	img = mlx_new_image(map->mlx, IMG_W, IMG_H);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	tx = extra_selector(map, c, x, y);
	mlx_draw_texture(img, tx, 0, 0);
	mlx_delete_texture(tx);
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
				|| map->structure[i][j] == 'C')
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

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	delete_map(map);
	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			generate_image(map, j, i, map->structure[i][j]);
			if (map->structure[i][j] == 'P' || map->structure[i][j] == 'V'
				|| map->structure[i][j] == 'C')
				create_extra_image(map, j, i);
		}
	}
	map_to_window(map);
}

//	Adaptar textura invisible, obligar a pillar moneda, ventana win and lose
//	Progrmar sprites con condiciones
//	IMPORTANTE: ADMINISTRAR IMAGENES EXTRA AL FINAL DEL ARRAY

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
	delete_map(&m);
	mlx_terminate(m.mlx);
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