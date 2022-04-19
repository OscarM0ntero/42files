/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_assigners.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:00:55 by omontero          #+#    #+#             */
/*   Updated: 2022/04/07 14:41:32 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

struct		s_parameters
{
	int		height;
	int		width;
	int		tam_square;
	char	gen;
	char	obs;
	char	sus;
	char	**mat;
};

void	ft_assign_matrix_size(struct s_parameters *param)
{
	int		i;

	i = 0;
	param->mat = (char **)malloc(param->height * sizeof(char *));
	while (i < param->height)
	{
		param->mat[i] = (char *)malloc(param->width * sizeof(char));
		i++;
	}
}

void	ft_print_matrix(struct s_parameters *param)
{
	int	i;

	i = 0;
	while (i < param->height)
	{
		ft_putstr(param->mat[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_write_square(struct s_parameters *param, int *esc)
{
	int		x;
	int		y;

	x = esc[0] - 1;
	while (x >= esc[0] - param->tam_square)
	{
		y = esc[1] - 1;
		while (y >= esc[1] - param->tam_square)
		{
			param->mat[y][x] = param->sus;
			y--;
		}
		x--;
	}
}

void	ft_matrix_assign(char *argv, struct s_parameters *param)
{
	int		i;
	int		j;
	int		fd;
	char	c;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1) && c != '\n')
		;
	while (read(fd, &c, 1) && j < param->height)
	{
		if (c != '\n' && c != '\0')
		{
			param->mat[j][i] = c;
			i++;
		}
		else
		{
			j++;
			i = 0;
		}
	}
}
