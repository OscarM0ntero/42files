/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/27 14:41:16 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Busca el mayor numero dentro del Stack
int	s_h(t_stack x)
{
	int	i;
	int	higher_number_found;

	higher_number_found = x.stk[0].val;
	i = 0;
	while (i < x.size)
	{
		if (higher_number_found < x.stk[i].val)
			higher_number_found = x.stk[i].val;
		i++;
	}
	return (higher_number_found);
}

int	search_higher_pos(t_stack x)
{
	int	i;
	int	higher_number_found;
	int	pos;

	higher_number_found = x.stk[0].val;
	i = 0;
	pos = 0;
	while (i < x.size)
	{
		if (higher_number_found < x.stk[i].val)
		{
			higher_number_found = x.stk[i].val;
			pos = x.stk[i].pos;
		}
		i++;
	}
	return (pos);
}

int	search_lower(t_stack x)
{
	int	i;
	int	lower_number_found;

	lower_number_found = x.stk[0].val;
	i = 0;
	while (i < x.size)
	{
		if (lower_number_found > x.stk[i].val)
			lower_number_found = x.stk[i].val;
		i++;
	}
	return (lower_number_found);
}

int	search_num_pos(t_stack x, int val)
{
	int	i;

	i = 0;
	while (i < x.size && x.stk[i].val != val)
		i++;
	if (i == x.size)
		i = -1;
	return (i);
}

int	search_higher_und_x(t_stack x, int max)
{
	int	i;
	int	greater;

	greater = search_lower(x);
	i = 0;
	while (i < x.size)
	{
		if (x.stk[i].val > greater && x.stk[i].val < max)
			greater = x.stk[i].val;
		i++;
	}
	return (greater);
}
