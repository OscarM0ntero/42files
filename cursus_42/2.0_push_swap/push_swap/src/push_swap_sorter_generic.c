/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter_generic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/24 13:04:53 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Devuelve la posicion del numero que hay 10 veces menor encontrado, o -1
int	search_num_x_under(int num, t_stack *a, t_data *data)
{
	int	i;
	int	j;
	int	numbers_found;
	int	pos;

	pos = search_num_pos(*a, num);
	numbers_found = 0;
	i = num - 1;
	while (i >= data->lowest_number && numbers_found < data->x)
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

void	rotate_extract_x_higher(t_stack *a, t_stack *b, t_data *data)
{
	int	i;
	int	n_extracted;
	int	low;

	n_extracted = 0;
	low = a->stk[search_num_x_under(data->highest_number_dis, a, data)].val;
	i = 0;
	while (i < data->total_amount_of_numbers && n_extracted <= data->x
		&& data->highest_number_dis != data->lowest_number)
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

void	organize_3(t_stack *a, t_data *data)
{
	if (order(a) == 1)
		return ;
	if (order(a) == 2)
		return (order_a(a, data));
	if (a->stk[0].val < a->stk[2].val)
	{
		if (a->stk[1].val > a->stk[2].val)
			ft_rra(a, 1);
	}
	else
		ft_ra(a, 1);
	ft_sa(a, 1);
	data->numbers_in_order = 3;
	data->highest_number_dis = search_lower(*a);
	data->lowest_number_ord = data->highest_number_dis;
}
	