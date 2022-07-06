/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/28 14:05:57 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	ft_sa(t_game g, int print)
{
	int	tmp;

	if (g.a.size >= 2)
	{
		tmp = g.a.stk[g.a.size - 1].val;
		g.a.stk[g.a.size - 1].val = g.a.stk[g.a.size - 2].val;
		g.a.stk[g.a.size - 2].val = tmp;
		if (!print)
			write(1, "sa\n", 3);
	}
	return (g);
}

t_game	ft_sb(t_game g, int print)
{
	int	tmp;

	if (g.b.size >= 2)
	{
		tmp = g.b.stk[g.b.size - 1].val;
		g.b.stk[g.b.size - 1].val = g.b.stk[g.b.size - 2].val;
		g.b.stk[g.b.size - 2].val = tmp;
		if (!print)
			write(1, "sb\n", 3);
	}
	return (g);
}

t_game	ft_ss(t_game g)
{
	if (g.a.size >= 2)
		ft_sa(g, 1);
	if (g.b.size >= 2)
		ft_sb(g, 1);
	write(1, "ss\n", 3);
	return (g);
}
