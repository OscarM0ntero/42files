/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/17 14:09:06 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_stack	*aa;
	t_stack	*bb;

	if (!b->size)
		return ;
	aa = a;
	bb = b;
	*a = ft_add_to_stack(a, b->stk[0].val, 1);
	*b = ft_remove_from_stack(b, 1);
	free (aa->stk);
	free (bb->stk);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_stack	*aa;
	t_stack	*bb;

	aa = a;
	bb = b;
	if (!a->size)
		return ;
	*b = ft_add_to_stack(b, a->stk[0].val, 1);
	*a = ft_remove_from_stack(a, 1);
	free (aa->stk);
	free (bb->stk);
	write(1, "pb\n", 3);
}
