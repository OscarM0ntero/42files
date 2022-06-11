/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/11 02:53:14 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_assign_a(int argc, char const *argv, int *a)
{
	while (argc > 0)
	{
		a[argc - 1] = argv[argc];
		argc--;
	}
}

int	main(int argc, char *argv)
{
	int	*a;
	int	*b;

	a = ft_calloc(argc - 1, sizeof(int));
	b = ft_calloc(argc - 1, sizeof(int));
	ft_assign_a(argc, argv, a);
}
