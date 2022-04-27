/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex8.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:14:01 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/03/22 15:42:01 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_combn(int n);

int	main(void)
{
	ft_print_combn(2);
	ft_putchar('\n');
	ft_print_combn(9);
	return (0);
}
