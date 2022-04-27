/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:19:19 by omontero          #+#    #+#             */
/*   Updated: 2022/04/02 13:05:43 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_to_hex(int c, int e)
{
	char	*base;

	base = "0123456789abcdef";
	if (c <= 0 && e == 0)
	{
		c += 256;
	}
	if (c >= 16)
	{
		ft_to_hex(c / 16, 1);
		ft_to_hex(c % 16, 1);
	}
	else
	{
		if (e == 0)
			ft_putchar('0');
		ft_putchar(base[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_to_hex(str[i], 0);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
