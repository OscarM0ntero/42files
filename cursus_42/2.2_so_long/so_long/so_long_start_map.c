/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/20 23:25:43 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_to_map(t_map *new_map, char *path)
{
	new_map->error = 0;
	new_map->n_chars = 0;
	new_map->path = ft_strdup(path);
	new_map->n_lines = count_lines(new_map->path);
	new_map->c_count = 0;
	new_map->game_over = 0;
	new_map->map_finished = 0;
	new_map->mv_count = 0;
	if (!new_map->n_lines)
		new_map->error = 1;
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
	new_map.structure = (char **)malloc(new_map.n_lines * sizeof(char *));
	fd = open(new_map.path, O_RDONLY);
	line = get_next_line(fd);
	new_map.n_chars = ft_strlen(line);
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
}
