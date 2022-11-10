/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/10 16:42:11 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Acabar el atoi long para escanear los limites del int y ver que no se pase
//	y comprobar repetidos con una funcion nueva

static int	ft_neg(int num, int x)
{
	if (x % 2 == 1)
	{
		num = num * -1;
	}
	return (num);
} 

long int	ft_atoi_long(const char *nptr)
{
	int			x;
	int			i;
	long int	num;

	i = 0;
	num = 0;
	x = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			x++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (ft_neg(num, x));
}
