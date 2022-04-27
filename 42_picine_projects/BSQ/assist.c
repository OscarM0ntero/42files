/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:31:55 by omontero          #+#    #+#             */
/*   Updated: 2022/04/07 14:43:16 by omontero         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	char	c;
	int		i;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		write(1, &c, 1);
		i++;
		c = str[i];
	}
}

int	ft_atoi(char *str)
{
	int	x;
	int	num;

	x = 0;
	num = 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = num * 10 + str[x] - 48;
		x++;
	}
	return (num);
}
