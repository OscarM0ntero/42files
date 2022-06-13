/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/13 14:16:36 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	ft_ra(t_game g, int print)
{
	size_t	i;
	int		tmp;

	if (g.a.size == 2)
	{
		if (!print)
			write(1, "ra\n", 3);
		return (ft_sa(g, 1));
	}
	else if (g.a.size < 2)
		return (g);
	i = g.a.size - 1;
	tmp = g.a.stk[g.a.size - 1].val;
	while (i > 0)
	{
		g.a.stk[i].val = g.a.stk[i - 1].val;
		g.a.stk[i].pos = i;
		i--;
	}
	g.a.stk[i].val = tmp;
	g.a.stk[i].pos = i;
	if (!print)
		write(1, "ra\n", 3);
	return (g);
}

t_game	ft_rb(t_game g, int print)
{
	size_t	i;
	int		tmp;

	if (g.b.size == 2)
	{
		if (!print)
			write(1, "rb\n", 3);
		return (ft_sb(g, 1));
	}
	else if (g.b.size < 2)
		return (g);
	i = g.b.size - 1;
	tmp = g.b.stk[g.b.size - 1].val;
	while (i > 0)
	{
		g.b.stk[i].val = g.b.stk[i - 1].val;
		g.b.stk[i].pos = i;
		i--;
	}
	g.b.stk[i].val = tmp;
	g.b.stk[i].pos = i;
	if (!print)
		write(1, "rb\n", 3);
	return (g);
}

t_game	ft_rr(t_game g)
{
	g = ft_ra(g, 1);
	g = ft_rb(g, 1);
	write(1, "rr\n", 3);
	return (g);
}
