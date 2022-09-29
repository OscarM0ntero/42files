/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/12 21:45:37 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	ft_pa(t_game g, int print)
{
	if (!g.b.size)
		return (g);
	ft_add_to_stack(g, g.b.stk[g.b.size - 1], 1, 0);
	ft_remove_from_stack(g, g.b.size - 1, 0, 1);
	if (!print)
		write(1, "pa\n", 3);
	return (g);
}

t_game	ft_pb(t_game g, int print)
{
	if (!g.a.size)
		return (g);
	g = ft_add_to_stack(g, g.a.stk[g.a.size - 1], 0, 1);
	g = ft_remove_from_stack(g, g.a.size - 1, 1, 0);
	if (!print)
		write(1, "pb\n", 3);
	return (g);
}
