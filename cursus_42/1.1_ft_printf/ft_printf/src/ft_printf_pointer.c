/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/10 15:13:06 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_in_hex(unsigned long long n)
{
	if (n >= 16)
	{
		ft_print_in_hex(n / 16);
		ft_print_in_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

static int	ft_hex_length(unsigned long long n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

int	ft_printpointer(unsigned long long p)
{
	int	length;

	length = 0;
	if (p == 0)
		length += ft_printstring("(nil)");
	else
	{
		length += write(1, "0x", 2);
		ft_print_in_hex(p);
		length += ft_hex_length(p);
	}
	return (length);
}
