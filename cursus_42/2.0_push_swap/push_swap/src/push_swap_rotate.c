/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/20 03:44:43 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int print)
{
	int		tmp;

	if (a->size < 2)
		return ;
	else if (a->size == 2)
		ft_sa(a, 0);
	else
	{
		tmp = a->stk[0].val;
		ft_remove_from_stack(a, 1);
		ft_add_to_stack(a, tmp, 0);
	}
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b, int print)
{
	int		tmp;

	if (b->size < 2)
		return ;
	else if (b->size == 2)
		ft_sb(b, 0);
	else
	{
		tmp = b->stk[0].val;
		ft_remove_from_stack(b, 1);
		ft_add_to_stack(b, tmp, 0);
	}
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write(1, "rr\n", 3);
}
