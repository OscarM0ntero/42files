/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:26:25 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 18:26:50 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	i;
	int	j;
	int	*a;
	int	*b;

	i = 11;
	j = 5;
	a = &i;
	b = &j;
	printf("%d /", i);
	printf(" %d\n", j);
	ft_ultimate_div_mod(a, b);
	printf("div (*a) = %d\n", *a);
	printf("mod (*b) = %d", *b);
}
