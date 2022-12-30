/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/12/30 12:49:56 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Lee los stack A y B y los imprime por pantalla
void	read_stack(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	printf("	Stack: A				Stack: B\n");
	while (i < a.size || i < b.size)
	{
		if (i < a.size)
			printf("Pos: %d		Value: %d		", a.stk[i].pos, a.stk[i].val);
		else
			printf("					");
		if (i < b.size)
			printf("Pos: %d		Value: %d", b.stk[i].pos, b.stk[i].val);
		printf("\n");
		i++;
	}
	printf("\n");
}

//	Se le pasa un stack, un valor a aniadir y 1 si al principio o 0 al fin
void	ft_add_to_stack(t_stack *stack, int new_val, int pos)
{
	t_stack	new_stack;
	t_value	*tmp;
	int		i;

	new_stack.size = stack->size + 1;
	new_stack.stk = ft_calloc(new_stack.size, sizeof(t_value));
	i = pos;
	while (i < new_stack.size)
	{
		new_stack.stk[i].val = stack->stk[i - pos].val;
		new_stack.stk[i].pos = i;
		i++;
	}
	if (pos)
		i = 1;
	i--;
	new_stack.stk[i].pos = i;
	new_stack.stk[i].val = new_val;
	tmp = stack->stk;
	*stack = new_stack;
	if (tmp)
		free (tmp);
}

//	Se pasa un stack y 1 si se borra el primer valor, o 0 si el ultimo
void	ft_remove_from_stack(t_stack *stack, int pos)
{
	t_stack	new_stack;
	t_value	*tmp;
	int		i;

	new_stack.size = stack->size - 1;
	new_stack.stk = ft_calloc(new_stack.size, sizeof(t_value));
	i = 0;
	while (i < new_stack.size)
	{
		new_stack.stk[i].val = stack->stk[i + pos].val;
		new_stack.stk[i].pos = i;
		i++;
	}
	tmp = stack->stk;
	*stack = new_stack;
	free (tmp);
}
