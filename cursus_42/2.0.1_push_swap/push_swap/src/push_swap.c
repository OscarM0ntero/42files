/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/26 14:04:29 by omontero         ###   ########.fr       */
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

void	organize_2(t_stack *a, t_data *data)
{
	if (a->stk[0].val > a->stk[1].val)
		ft_sa(a, 1);
	data->numbers_in_order = 2;
	data->highest_number_dis = search_lower(*a);
	data->lowest_number_ord = data->highest_number_dis;
}

//	Devuelve 0 si no hay orden, 1 si hay orden
int	order_in_some_way(t_stack *a, t_data *data)
{
	int	l_p;
	int	h_p;
	int	dir;

	dir = 0;
	l_p = search_lower_pos(*a);
	h_p = search_higher_pos(*a);
	if (l_p + 1 == h_p || l_p - 1 == h_p || (h_p == 0 || l_p == 0)
		&& (h_p == a->size - 1 || l_p == a->size - 1))
		
	return (dir);
}

void	organize(t_stack *a, t_stack *b, t_data *data)
{
	while (data->total_amount_of_numbers != data->numbers_in_order)
	{
		// if (data->total_amount_of_numbers - data->numbers_in_order > 200)
		// 	rotate_extract_100_higher(a, b, data);
		// else
		// 	rotate_extract_10_higher(a, b, data);
		if (data->total_amount_of_numbers == 2)
			organize_2(a, data);
		else if (data->total_amount_of_numbers <= 10)
			organize_10(a, b, data);	// ????
		else
		{
			rotate_extract_x_higher(a, b, data);
			extract_in_order(a, b, data);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	data.total_amount_of_numbers = argc - 1;
	if (data.total_amount_of_numbers < 20)
		data.x = data.total_amount_of_numbers;
	else if (data.total_amount_of_numbers < 400)
		data.x = data.total_amount_of_numbers / 5;
	else if (data.total_amount_of_numbers < 1200)
		data.x = data.total_amount_of_numbers / 10;
	else
		data.x = data.total_amount_of_numbers / 20;
	data.numbers_in_order = 0;
	assign_values(argv, &a, data);
	data.highest_number = search_higher(a);
	data.lowest_number = search_lower(a);
	data.highest_number_dis = data.highest_number;
	data.lowest_number_ord = data.highest_number;
	organize(&a, &b, &data);
	return (0);
}

//read_stack(a, b);
