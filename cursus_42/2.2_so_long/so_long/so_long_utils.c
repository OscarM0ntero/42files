/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/21 00:31:25 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	size_t	i;
	size_t	j;

	generate_map(map);
	i = -1;
	write(1, "\n\n\n\n", 4);
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_chars)
			write(1, &map->structure[i][j], 1);
		if (!i)
		{
			write(1, "\t\tCoins: ", 9);
			write(1, new_itoa(map->c_count), 1);
			write(1, " Win: ", 6);
			write(1, new_itoa(map->map_finished), 1);
			write(1, " GameOver: ", 11);
			write(1, new_itoa(map->game_over), 1);
		}
		write(1, "\n", 1);
	}
}

//	Comentar TODAS LAS FUNCIONES, continuar con el move para E y C, comprobar
//	errores para que haya 1 E y minimo 1 C, asi como incluir enemigos y su movimiento

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
		if (!ft_strchr("01PECV", line[i]))
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
