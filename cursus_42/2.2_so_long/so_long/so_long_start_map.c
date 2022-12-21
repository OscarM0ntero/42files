/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/21 16:02:41 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_to_map(t_map *map, char *path)
{
	map->move = 1;
	map->img_assigned = 0;
	map->error = 0;
	map->n_chars = 0;
	map->path = ft_strdup(path);
	map->n_lines = count_lines(map->path);
	map->c_count = 0;
	map->game_over = 0;
	map->map_finished = 0;
	map->mv_count = 0;
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
	map->n_coins = check_exit_and_coin(map);
	map->image = (mlx_image_t **)malloc((map->n_images + map->n_coins
				+ map->n_enemies + 2) * sizeof(mlx_image_t *));
}
