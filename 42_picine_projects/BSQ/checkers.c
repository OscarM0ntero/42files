/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:30:23 by omontero          #+#    #+#             */
/*   Updated: 2022/04/07 14:43:10 by omontero         ###   ########.fr       */
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

int	ft_first_check(struct s_parameters *param, int x, int y)
{
	int		i;
	int		q;

	i = 0;
	while (i < param->tam_square)
	{
		q = 0;
		while (q < param->tam_square)
		{
			if (param->mat[i + y][q + x] == param->obs)
				return (1);
			q++;
		}
		i++;
	}
	return (0);
}

int	*ft_second_check(struct s_parameters *param, int x, int y)
{
	int		i;
	int		q;
	int		*esc;

	esc = ((int *)malloc(2 * sizeof(int)));
	i = 0;
	esc[0] = -1;
	esc[1] = -1;
	while (i < param->tam_square)
	{
		q = 0;
		while (q < param->tam_square)
		{
			if (param->mat[i + y][q + x] == param->obs)
				return (esc);
			q++;
		}
		i++;
	}
	esc[0] = i + x;
	esc[1] = i + y;
	return (esc);
}

int	ft_move_square(struct s_parameters *param)
{
	int		x;
	int		y;

	y = 0;
	while (y <= param->height - param->tam_square)
	{
		x = 0;
		while (x <= param->width - param->tam_square)
		{
			if (ft_first_check(param, x, y) == 0)
			{
				return (param->tam_square);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	*ft_move_square2(struct s_parameters *param)
{
	int		x;
	int		y;

	y = 0;
	while (y <= param->height - param->tam_square)
	{
		x = 0;
		while (x <= param->width - param->tam_square)
		{
			if (ft_second_check(param, x, y)[0] != -1 &&
				ft_second_check(param, x, y)[1] != -1)
				return (ft_second_check(param, x, y));
			x++;
		}
		y++;
	}
	return (ft_second_check(param, x, y));
}
