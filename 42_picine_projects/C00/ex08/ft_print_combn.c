/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:02:25 by omontero          #+#    #+#             */
/*   Updated: 2022/03/30 10:42:00 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_asignar_array(int *first_pointer, int num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		first_pointer[8 - i] = num % 10;
		num /= 10;
		i++;
	}
}

void	imprimir(int *first_pointer, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = first_pointer[9 - n + i] + '0';
		write(1, &c, 1);
		if (i == n - 1 && first_pointer[9 - n] != 10 - n)
			write(1, ", ", 2);
		i++;
	}
}

void	ft_check_and_print(int *first_pointer, int num, int n)
{
	int	i;
	int	imprimible;

	if (num == 23456790)
		num = 123456789;
	ft_asignar_array(first_pointer, num, n);
	imprimible = 1;
	i = 0;
	while (i < n)
	{
		if (first_pointer[9 - n + i] >= first_pointer[9 - n + i + 1] && i < n
			- 1)
		{
			imprimible = 0;
		}
		i++;
	}
	if (imprimible == 1)
	{
		imprimir(first_pointer, n);
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	max;
	int	num_array[9];
	int	*first_pointer;

	first_pointer = &num_array[0];
	i = 0;
	max = 1;
	while (i < n)
	{
		max *= 10;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		num_array[i] = 0;
		i++;
	}
	i = 0;
	while (i < max && i <= 23456790)
	{
		ft_check_and_print(first_pointer, i, n);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putchar(char c);
void	ft_print_combn(int n);

int	main(void)
{
	ft_print_combn(2);
	ft_putchar('\n');
	ft_print_combn(9);
	return (0);
}
