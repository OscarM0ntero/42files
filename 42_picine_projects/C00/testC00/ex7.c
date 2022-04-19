/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex7.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:14:01 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/03/22 16:02:12 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

int	main(void)
{
	ft_putnbr(5);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-4);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	return (0);
}
