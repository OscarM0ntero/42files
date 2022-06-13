/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/13 14:21:22 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	ft_rra(t_game g, int print)
{
	size_t	i;
	int		tmp;

	if (g.a.size == 2)
	{
		if (!print)
			write(1, "rra\n", 4);
		return (ft_sa(g, 1));
	}
	else if (g.a.size < 2)
		return (g);
	i = 0;
	tmp = g.a.stk[0].val;
	while (i < g.a.size - 1)
	{
		g.a.stk[i].val = g.a.stk[i + 1].val;
		g.a.stk[i].pos = i;
		i++;
	}
	g.a.stk[i].val = tmp;
	g.a.stk[i].pos = i;
	if (!print)
		write(1, "rra\n", 4);
	return (g);
}

t_game	ft_rrb(t_game g, int print)
{
	size_t	i;
	int		tmp;

	if (g.b.size == 2)
	{
		if (!print)
			write(1, "rrb\n", 4);
		return (ft_sb(g, 1));
	}
	else if (g.b.size < 2)
		return (g);
	i = 0;
	tmp = g.b.stk[0].val;
	while (i < g.b.size - 1)
	{
		g.b.stk[i].val = g.b.stk[i + 1].val;
		g.b.stk[i].pos = i;
		i++;
	}
	g.b.stk[i].val = tmp;
	g.b.stk[i].pos = i;
	if (!print)
		write(1, "rrb\n", 4);
	return (g);
}

t_game	ft_rrr(t_game g)
{
	g = ft_rra(g, 1);
	g = ft_rrb(g, 1);
	write(1, "rrr\n", 4);
	return (g);
}
