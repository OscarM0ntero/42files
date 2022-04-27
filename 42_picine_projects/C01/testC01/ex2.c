/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:26:56 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 18:27:21 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	i;
	int	j;
	int	*a;
	int	*b;

	i = 7;
	j = 3;
	a = &i;
	b = &j;
	printf("i=%d j=%d ==> execute swap:\n", *a, *b);
	ft_swap(a, b);
	printf("ahora i debe ser 3, y es -> %u\n", *a);
	printf("ahora j debe ser 7, y es -> %u", *b);
}
