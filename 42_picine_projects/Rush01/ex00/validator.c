/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:17:12 by omontero          #+#    #+#             */
/*   Updated: 2022/03/27 13:40:22 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define TAM 4

int	ft_check_value(int value, int *param, int x, int y)
{
	if(x == 0 && y == 0)
}

void	ft_validator(int *matrix[TAM][TAM], int *param[16])
{
	int x;
	int y;
	int bit;

	x = 0;
	y = 0;
	bit = 1;
	while(y < TAM)
	{
		x = 0;
		while (x < TAM)
		{
			if (!ft_check_value(matrix[y][x], param, x, y)
			{
				bit = 0;
			}
			x++;
		}
		y++;
	}
}
