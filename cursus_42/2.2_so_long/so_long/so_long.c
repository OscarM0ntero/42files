/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/19 16:03:00 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1280
#define HEIGHT 768
#define IMG_WIDTH 64
#define IMG_HEIGHT 64

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 5;
}

size_t	count_lines(char *p)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(p, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	if (line != NULL)
	{
		while (line != NULL)
		{
			count++;
			free (line);
			line = get_next_line(fd);
		}
	}
	free (line);
	close(fd);
	return (count);
}

void	check_line(char *line, t_map *new_map)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != new_map->n_chars && !new_map->error)
		new_map->error = 2;
	while (line[i] && !new_map->error)
	{
		if (!ft_strchr("10PEC", line[i]))
			new_map->error = 3;
		i++;
	}
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
	new_map.error = 0;
	new_map.path = ft_strdup(p);
	new_map.n_lines = count_lines(new_map.path);
	if (!new_map.n_lines)
		new_map.error = 1;
	new_map.structure = (char **)malloc(new_map.n_lines * sizeof(char *));
	fd = open(new_map.path, O_RDONLY);
	line = get_next_line(fd);
	new_map.n_chars = ft_strlen(line);
	check_line(line, &new_map);
	while (n_lin < new_map.n_lines && !new_map.error)
	{
		new_map.structure[n_lin] = line;
		line = get_next_line(fd);
		if (line && ft_strlen(line) != new_map.n_chars)
			new_map.error = 1;
		n_lin++;
	}
	close(fd);
	return (new_map);
}

/*
*	Error code
*	1 = Empty file
*	2 = Different number of chars per line
*	3 = Invalid char found !(0, 1, P, E, C)
*	4 = Not surrounded by 1s (not closed)
*/

int	main(int argc, char **argv)
{
	t_map	map;
	size_t	i;

	if (argc != 2)
		return (printf("Error: No map introduced.\n"), 1);
	i = 0;
	map = read_map(argv[1]);
	printf("%s\n%ld\n%ld\n%i\n", map.path, map.n_chars, map.n_lines, map.error);
	while (i < map.n_lines)
	{
		printf("%s\n", map.structure[i]);
		i++;
	}
	return (0);
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