/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/21 16:03:25 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define IMG_W 64
#define IMG_H 64

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
	// if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	// {
	// 	start(map, map->path);
	// 	print_map(map);
	// }

mlx_texture_t	*texture(char c, size_t x, size_t y, t_map *map)
{
	(void)x;
	(void)y;
	(void)map;
	if (c == '1')
		return (mlx_load_png("sprites/wall_mid.png"));
	else if (c == 'P' || c == 'V')
		return (mlx_load_png("sprites/capybara.png"));
	else if (c == 'E')
		return (mlx_load_png("sprites/exit_floor.png"));
	else if (c == 'C')
		return (mlx_load_png("sprites/coins2.png"));
	else
		return (mlx_load_png("sprites/floor1.png"));
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
	mlx_delete_texture(tx);
	//mlx_image_to_window(map->mlx, g_img, x * IMG_W, y * IMG_H);
	map->img_assigned = 1;
	map->image[(y * map->n_chars) + x] = g_img;
}

void	delete_map(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->n_images)
	{
		mlx_delete_image(map->mlx, map->image[i]);
	}
}

void	map_to_window(t_map *map)
{
	size_t			i;
	size_t			j;
	mlx_texture_t	*tx;
	mlx_image_t		*img;

	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			if (map->structure[i][j] == 'P' || map->structure[i][j] == 'V'
				|| map->structure[i][j] == 'C')
			{
				if (map->structure[i][j] == 'P' && !map->move)
					tx = mlx_load_png("sprites/exit_floor.png");
				else
					tx = mlx_load_png("sprites/floor1.png");
				img = mlx_new_image(map->mlx, IMG_W, IMG_H);
				memset(img->pixels, 255, img->width * img->height
					* sizeof(int));
				mlx_draw_texture(img, tx, 0, 0);
				mlx_image_to_window(map->mlx, img, j * IMG_W, i * IMG_H);
				mlx_delete_texture(tx);
			}
			mlx_image_to_window(map->mlx, map->image[(i * map->n_chars) + j],
				j * IMG_W, i * IMG_H);
		}
	}
}

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	if (map->img_assigned)
		delete_map(map);
	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
		{
			generate_image(map, j, i, map->structure[i][j]);
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
	m.mlx = mlx_init(m.n_chars * 64, m.n_lines * 64, "So_Long", true);
	if (!m.mlx)
		exit(EXIT_FAILURE);
	if (!m.error)
		print_map(&m);
	mlx_key_hook(m.mlx, &keyhook, &m);
	mlx_loop(m.mlx);
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