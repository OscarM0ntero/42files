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

//	Se le pasa un stack, un valor a aniadir y 0 si se aniade al principio o 1
//	si se aniade al final
void	ft_add_to_stack(t_stack	*stack, int	new_val, int pos)
{
	t_stack	new_stack;
	t_stack	*tmp;
	int		i;

	i = pos;
	tmp = stack;
	new_stack.size = *stack->size + 1;
	new_stack.stk = ft_calloc(new_stack.size, sizeof(t_value));
	while (i < new_stack.size - pos)
	{
		new_stack.stk[i].val = *stack->stk[i].val;
		new_stk.stk[i].pos = i;
		i++;
	}
	i = 0;
	if(pos)
		i = new_stack.size - 1;
	new_stack.stk[i].pos = i;
	new_stack.stk[i].val = new_val;
	//	Asignamos el nuevo stack generado al introducido de origen,
	//	y liberamos el stack viejo.
	stack = *new_stack;
	free(tmp);
}

//	Se pasa un stack y 0 si se borra el primer valor, o 1 si el ultimo
void	ft_remove_from_stack(t_stack *stack, int pos)
{
	t_value *tmp;
	int		i;

	i = 0;
	tmp = *stack->stk[0];
	*stack->size =- 1;
	if(pos)
		free(*stack->stk[stack->size]);
	else
	{
		*stack->stk += 1;
		tmp->val = 0;
		while (i < *stack->size)
		{
			*stack->stk[i].pos = i;
			i++;
		}
	}
		
}

void	ft_pa(t_stack *a, t_stack *b, int print)
{
	if (!*b.size)
		return ;
		
    ft_add_to_stack(*a, b->stk[0])
	if (print)
		write(1, "pa\n", 3);
	return (g);
}