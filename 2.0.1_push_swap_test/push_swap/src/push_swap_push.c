/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/03 19:48:34 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	*a = ft_add_to_stack(a, b->stk[0].val, 1);
	*b = ft_remove_from_stack(b, 1);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	*b = ft_add_to_stack(b, a->stk[0].val, 1);
	*a = ft_remove_from_stack(a, 1);
	write(1, "pb\n", 3);
}
