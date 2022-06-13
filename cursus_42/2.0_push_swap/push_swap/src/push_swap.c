/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/13 14:20:54 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Assign to game struct the values introduced by the user
	and assign memory to the stacks */
static t_game	ft_assign_values(int argc, char **argv)
{
	t_game	g;

	g.argv = argv;
	g.a.size = argc - 1;
	g.b.size = 0;
	g.a.stk = ft_calloc(g.a.size, sizeof(t_value));
	return (g);
}

//	Assign on stack A the iput values
static void	ft_assign_a(t_game g)
{
	size_t	i;

	i = 0;
	while (i < g.a.size)
	{
		g.a.stk[i].val = ft_atoi(g.argv[i + 1]);
		g.a.stk[i].pos = i;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	g;
	int		i;

	g = ft_assign_values(argc, argv);
	ft_assign_a(g);
	//g = ft_sa(g);
	g = ft_pb(g, 0);
	g = ft_pb(g, 0);
	g = ft_rrr(g);
	i = (int)g.a.size - 1;
	while (i >= 0)
	{
		printf("A_pos %ld: %d\n", g.a.stk[i].pos, g.a.stk[i].val);
		i--;
	}
	i = (int)g.b.size - 1;
	if (i >= 0)
		write(1, "\n", 1);
	while (i >= 0)
	{
		printf("B_pos %ld: %d\n", g.b.stk[i].pos, g.b.stk[i].val);
		i--;
	}
	return (0);
}

//	Continuar con la instruccion rra en push_swap_reverse_rotate.c