/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:22:07 by abrik-sa          #+#    #+#             */
/*   Updated: 2022/04/04 11:39:14 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	longitud(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	decimal(int ln)
{
	int	i;
	int	d;

	d = 1;
	i = 1;
	while (i < ln)
	{
		d = d * 10;
		i++;
	}
	return (d);
}

void	imprimir(int nb, int d, int ln)
{
	char	c;
	int		i;

	i = 0;
	while (i < ln)
	{
		c = nb / d + '0';
		write(1, &c, 1);
		nb = nb % d;
		d /= 10;
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb != 0)
		imprimir(nb, decimal(longitud(nb)), longitud(nb));
	else
		write(1, "0", 1);
}
