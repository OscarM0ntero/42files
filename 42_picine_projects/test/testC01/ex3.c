/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:46:49 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 18:27:14 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 5;
	b = 2;
	div = &a;
	mod = &b;
	ft_div_mod(a, b, div, mod);
	printf("\nesto debe ser 2 -> %u", *div);
	printf("\nesto debe ser 1 -> %u", *mod);
}
