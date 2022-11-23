/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/23 11:37:13 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_a(t_stack *a, t_data *data)
{
	while (a->stk[0].val != data->lowest_number)
		if (search_num_pos(*a, search_lower(*a))
			> data->total_amount_of_numbers / 2)
			ft_rra(a, 1);
	else
		ft_ra(a, 1);
}

void	realloc_a(t_stack *a, t_data *data)
{
	int	low_n_ord_pos;

	low_n_ord_pos = search_num_pos(*a, data->lowest_number_ord);
	while (a->stk[0].val != data->lowest_number_ord && a->stk)
	{
		if (low_n_ord_pos < a->size / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}

//	Devuelve la posicion del numero que hay 10 veces menor encontrado, o -1
int	search_num_10_under(int num, t_stack *a, t_data *data)
{
	int	i;
	int	j;
	int	numbers_found;
	int	pos;

	pos = search_num_pos(*a, num);
	numbers_found = 0;
	i = num - 1;
	while (i >= data->lowest_number && numbers_found < 10)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->stk[j].val == i)
			{
				numbers_found++;
				pos = a->stk[j].pos;
			}
			j++;
		}
		i--;
	}
	return (pos);
}

void	rotate_extract_10_higher(t_stack *a, t_stack *b, t_data *data)
{
	int	i;
	int	n_extracted;
	int	low;

	n_extracted = 0;
	low = a->stk[search_num_10_under(data->highest_number_dis, a, data)].val;
	i = 0;
	while (i < data->total_amount_of_numbers && n_extracted <= 10)
	{
		if (a->stk[0].val >= low && a->stk[0].val <= data->highest_number_dis)
		{
			ft_pb(a, b);
			n_extracted++;
		}
		else if (data->numbers_in_order < data->total_amount_of_numbers / 2)
			ft_ra(a, 1);
		else if (search_num_pos(*a, data->highest_number) != a->size - 1)
			ft_rra(a, 1);
		i++;
	}
	if (data->highest_number_dis != data->lowest_number_ord)
	{
		realloc_a(a, data);
	}
}

//	Devuelve los valores en orden del stack B al A
void	extract_in_order(t_stack *a, t_stack *b, t_data *data)
{
	int	highest_in_b_pos;
	int	highest_in_b;

	data->lowest_number_ord = search_lower(*b);
	data->highest_number_dis = search_higher_und_x(*a, data->lowest_number_ord);
	while (b->size)
	{
		highest_in_b = s_h(*b);
		highest_in_b_pos = search_higher_pos(*b);
		while (b->stk[0].val != highest_in_b)
		{
			if (highest_in_b_pos <= b->size / 2)
				ft_rb(b, 1);
			else
				ft_rrb(b, 1);
		}
		ft_pa(a, b);
		data->numbers_in_order++;
	}
}
