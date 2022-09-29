/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/06/12 20:26:43 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Takes the old_stk and create a new one, adding a new
	value on top if assign is true*/
t_stack	ft_assign_stack(t_stack old_stk, t_value new_val, int assign)
{
	size_t	i;
	t_stack	new_stk;

	new_stk.size = old_stk.size + assign;
	new_stk.stk = ft_calloc(new_stk.size, sizeof(t_value));
	i = 0;
	while (i < new_stk.size - assign)
	{
		new_stk.stk[i].val = old_stk.stk[i].val;
		new_stk.stk[i].pos = i;
		i++;
	}
	if (assign)
	{
		new_stk.stk[i].val = new_val.val;
		new_stk.stk[i].pos = i;
	}
	return (new_stk);
}

/*	Adds a value on top of the stack, you have to mark if you 
	want to add it to A, B or both by setting it to 1(y) or 0(n)*/
t_game	ft_add_to_stack(t_game g, t_value new_val, int a, int b)
{
	if (a && b)
	{
		g.a = ft_assign_stack(g.a, new_val, 1);
		g.b = ft_assign_stack(g.b, new_val, 1);
	}
	else if (a && !b)
		g.a = ft_assign_stack(g.a, new_val, 1);
	else if (!a && b)
		g.b = ft_assign_stack(g.b, new_val, 1);
	return (g);
}

t_stack	ft_remove(t_stack old_stk, size_t pos)
{
	size_t	i;
	size_t	j;
	t_stack	new_stk;

	new_stk.size = old_stk.size - 1;
	new_stk.stk = ft_calloc(new_stk.size, sizeof(t_value));
	i = 0;
	j = 0;
	while (i < old_stk.size)
	{
		if (i != pos)
		{
			new_stk.stk[j].val = old_stk.stk[i].val;
			new_stk.stk[j].pos = j;
			j++;
		}
		i++;
	}
	return (new_stk);
}

t_game	ft_remove_from_stack(t_game g, size_t pos, int a, int b)
{
	if (a && b)
	{
		g.a = ft_remove(g.a, pos);
		g.b = ft_remove(g.b, pos);
	}
	else if (a && !b)
		g.a = ft_remove(g.a, pos);
	else if (!a && b)
		g.b = ft_remove(g.b, pos);
	return (g);
}
