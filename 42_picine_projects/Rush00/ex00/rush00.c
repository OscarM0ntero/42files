/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 08:47:12 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 13:26:55 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
A F F F B
G E E E G
G E E E G
C F F F D
*/

void	ft_putchar(char c);

void	pos_check_and_print(int x, int y, int i, int j)
{
	if (i == 0 && j == 0)
		ft_putchar('o');
	else if (i == x && j == 0)
		ft_putchar('o');
	else if (i == 0 && j == y)
		ft_putchar('o');
	else if (i == x && j == y)
		ft_putchar('o');
	else if (i != 0 && i != x && (j == 0 || j == y))
		ft_putchar('-');
	else if (j != 0 && j != y && (i == 0 || i == x))
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x > 0 && y > 0)
	{
		x -= 1;
		y -= 1;
		j = 0;
		while (j <= y)
		{
			i = 0;
			while (i <= x)
			{
				pos_check_and_print(x, y, i, j);
				i++;
			}
			j++;
			ft_putchar('\n');
		}
	}
}
