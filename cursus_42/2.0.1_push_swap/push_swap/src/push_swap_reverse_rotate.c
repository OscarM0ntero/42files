/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/03 18:17:23 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int print)
{
	int	tmp;

	if (a->size < 2)
		return ;
	else if (a->size == 2)
		ft_sa(a, 0);
	else
	{
		tmp = a->stk[a->size - 1].val;
		*a = ft_remove_from_stack(a, 0);
		*a = ft_add_to_stack(a, tmp, 1);
	}
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, int print)
{
	int	tmp;

	if (b->size < 2)
		return ;
	else if (b->size == 2)
		ft_sb(b, 0);
	else
	{
		tmp = b->stk[0].val;
		*b = ft_remove_from_stack(b, 1);
		*b = ft_add_to_stack(b, tmp, 0);
	}
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr\n", 4);
}
