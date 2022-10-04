/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/04 18:48:06 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Esta funcion asigna los valores introduciodos por consola
//	al stack A de inicio :)

void	assign_values(char **argv, t_stack *a, t_data data)
{
	int	i;

	i = 0;
	a->size = data.total_amount_of_numbers;
	a->stk = ft_calloc(a->size, sizeof(t_value));
	while (i < data.total_amount_of_numbers)
	{
		a->stk[i].val = ft_atoi(argv[i + 1]);
		a->stk[i].pos = i;
		i++;
	}
}

//	Busca el mayor numero dentro del Stack
int	search_higher(t_stack x)
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

int	seach_num_pos(t_stack x, int val)
{
	int	i;

	i = 0;
	while (i < x.size && x.stk[i].val != val)
		i++;
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

//	Devuelve la posicion del numero que hay 10 veces menor encontrado, o -1
int	search_num_10_under(int num, t_stack *a, t_data *data)
{
	int	i;
	int	j;
	int	numbers_found;
	int	pos;

	pos = seach_num_pos(*a, num);
	numbers_found = 0;
	i = num - 1;
	while (i >= data->lowest_number && numbers_found < 9)
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

void	realloc_a(t_stack *a, t_data *data)
{
	int	low_n_ord_pos;

	low_n_ord_pos = seach_num_pos(*a, data->lowest_number_ord);
	while (a->stk[0].val != data->lowest_number_ord)
	{
		if (low_n_ord_pos <= a->size / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}

void	rotate_extract_10_higher(t_stack *a, t_stack *b, t_data *data)
{
	int	i;
	int	n_extracted;
	int	low;

	n_extracted = 0;
	low = a->stk[search_num_10_under(data->highest_number_dis, a, data)].val;
	i = 0;
	while (i < data->total_amount_of_numbers && n_extracted < 10)
	{
		if (a->stk[0].val >= low && a->stk[0].val <= data->highest_number_dis)
		{
			ft_pb(a, b);
			n_extracted++;
		}
		else
			ft_ra(a, 1);
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
		highest_in_b = search_higher(*b);
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

void	organize(t_stack *a, t_stack *b, t_data *data)
{
	while (data->total_amount_of_numbers != data->numbers_in_order)
	{
		rotate_extract_10_higher(a, b, data);
		extract_in_order(a, b, data);
	}
}

/*
	1. Pasar X caracteres de A a B mas
	2. Rotar B e ir sacando caracteres de B en orden de mayor a menor
*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	data.total_amount_of_numbers = argc - 1;
	data.numbers_in_order = 0;
	assign_values(argv, &a, data);
	data.highest_number = search_higher(a);
	data.lowest_number = search_lower(a);
	data.highest_number_dis = data.highest_number;
	data.lowest_number_ord = data.highest_number;
	read_stack(a, b);
	organize(&a, &b, &data);
	read_stack(a, b);
	return (0);
}
