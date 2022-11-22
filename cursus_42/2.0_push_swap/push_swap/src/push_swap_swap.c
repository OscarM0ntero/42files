/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/22 14:36:43 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int print)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->stk[0].val;
	a->stk[0].val = a->stk[1].val;
	a->stk[1].val = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int print)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->stk[0].val;
	b->stk[0].val = b->stk[1].val;
	b->stk[1].val = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}
