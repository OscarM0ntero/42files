/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/20 00:48:07 by omontero         ###   ########.fr       */
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

int	all_ones(char *line)
{
	while (*line && *line == '1')
		line++;
	if (*line)
		return (1);
	return (0);
}

void	check_line(char *line, size_t n_lin, t_map *new_map)
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
	if (n_lin == 0 && all_ones(line) && !new_map->error)
		new_map->error = 4;
	else if (n_lin == new_map->n_lines - 1 && all_ones(line) && !new_map->error)
		new_map->error = 4;
	else if ((line[0] != '1' || line[new_map->n_chars - 1] != '1')
		&& !new_map->error)
		new_map->error = 4;
}

void	print_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->n_lines)
	{
		j = 0;
		while (j < map->n_lines)
		{
			write(1, &map->structure[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
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
	new_map.n_chars = 0;
	new_map.path = ft_strdup(p);
	new_map.n_lines = count_lines(new_map.path);
	if (!new_map.n_lines)
		new_map.error = 1;
	if (new_map.error)
		return (new_map);
	new_map.structure = (char **)malloc(new_map.n_lines * sizeof(char *));
	fd = open(new_map.path, O_RDONLY);
	line = get_next_line(fd);
	new_map.n_chars = ft_strlen(line);
	//check_line(line, &new_map);
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

/*
*	Error code
*	1 = Empty file
*	2 = Different number of chars per line
*	3 = Invalid char found !(0, 1, P, E, C)
*	4 = Not surrounded by 1s (not closed)
*/

int	error_handler(int error)
{
	if (error == 1)
		return (printf("Error. Empty file.\n"), 1);
	else if (error == 2)
		return (printf("Error. Different lines lenghts.\n"), 1);
	else if (error == 3)
		return (printf("Error. Invalid char in map (Allowed: 01PEC).\n"), 1);
	else if (error == 4)
		return (printf("Error. Map not surrounded by 1's.\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (printf("Error: No map introduced.\n"), 1);
	map = read_map(argv[1]);
	error_handler(map.error);
	printf("%s\n%ld\n%ld\n%i\n", map.path, map.n_chars, map.n_lines, map.error);
	print_map(&map);
	//	Crear hook
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