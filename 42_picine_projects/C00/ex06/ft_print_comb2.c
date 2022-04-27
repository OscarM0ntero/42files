/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:35:08 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 09:53:44 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	imprimir(int i, int j, int k, int l)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = i + '0';
	b = j + '0';
	c = k + '0';
	d = l + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(i == 9 && j == 8 && k == 9 && l == 9))
		write(1, ", ", 2);
}

void	combinaciones(int i, int j, int k, int l)
{
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			k = 0;
			while (k < 10)
			{
				l = 1;
				while (l < 10)
				{
					if (i < k || (i == k && j < l))
					{
						imprimir(i, j, k, l);
					}
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 1;
	combinaciones(i, j, k, l);
}
