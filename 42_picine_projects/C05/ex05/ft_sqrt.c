/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:36:14 by antrujil          #+#    #+#             */
/*   Updated: 2022/04/05 18:09:00 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	calcula(int num, int pos)
{
	while (pos <= 50000)
	{
		if (pos * pos == num)
			return (pos);
		pos++;
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	long	num;
	int		m;

	num = nb;
	if (num <= 0)
		return (0);
	else if (num == 1)
		return (1);
	m = INT_MAX / 2;
	if (num < m)
		return (calcula(num, 2));
	else
		return (calcula(num, 32500));
}
