/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/21 02:44:13 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1280
#define HEIGHT 768
#define IMG_W 64
#define IMG_H 64

mlx_image_t	*g_img;

//	Comentar TODAS LAS FUNCIONES, continuar con el move para E y C, comprobar
//	errores para que haya 1 E y minimo 1 C, asi como incluir enemigos y su movimiento

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(1, map);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(2, map);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(3, map);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(4, map);
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		|| map->map_finished || map->game_over)
		mlx_close_window(map->mlx);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		start(map, map->path);
		print_map(map);
	}
}

mlx_texture_t	*texture(char c, size_t x, size_t y, t_map *map)
{
	if (c == '1' && y < map->n_lines - 1 && map->structure[y + 1][x] == '0')
		return (mlx_load_png("sprites/wall_up.png"));
	else if (c == '1' && x == map->n_chars - 1)
		return (mlx_load_png("sprites/wall_right.png"));
	else if (c == '1' && x == 0)
		return (mlx_load_png("sprites/wall_left.png"));
	else if (c == '1' && y < map->n_lines && map->structure[y - 1][x] == '0')
		return (mlx_load_png("sprites/wall_down2.png"));
	else if (c == '1')
		return (mlx_load_png("sprites/wall_mid.png"));
	else if (c == '0')
		return (mlx_load_png("sprites/floor1.png"));
	else if (c == 'P')
		return (mlx_load_png("sprites/floor1.png"));
	else if (c == 'E')
		return (mlx_load_png("sprites/exit_floor.png"));
	else if (c == 'C')
		return (mlx_load_png("sprites/floor1.png"));
	else if (c == 'V')
		return (mlx_load_png("sprites/floor1.png"));
	else
		return (mlx_load_png("sprites/floor5.png"));
	return (0);
}

void	generate_image(t_map *map, int32_t x, int32_t y, char c)
{
	g_img = mlx_new_image(map->mlx, IMG_W, IMG_H);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_draw_texture(g_img, texture(c, x, y, map), 0, 0);
	if (c == 'P' || c == 'V')
		mlx_draw_texture(g_img, mlx_load_png("sprites/capybara.png"), 0, 0);
	if (c == 'C')
		mlx_draw_texture(g_img, mlx_load_png("sprites/coins2.png"), 0, 0);
	mlx_image_to_window(map->mlx, g_img, x * IMG_W, y * IMG_H);
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
			generate_image(map, j, i, map->structure[i][j]);
	}
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
	generate_map(&m);
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