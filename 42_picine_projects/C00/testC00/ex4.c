/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:14:01 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/03/22 15:43:49 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_is_negative(int n);

int	main(void)
{
	ft_is_negative(4);
	ft_putchar('\n');
	ft_is_negative(0);
	ft_putchar('\n');
	ft_is_negative(-6);
	return (1);
}
