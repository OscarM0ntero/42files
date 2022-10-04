/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/04 20:00:26 by oscar            ###   ########.fr       */
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

void	organize(t_stack *a, t_stack *b, t_data *data)
{
	while (data->total_amount_of_numbers != data->numbers_in_order)
	{
		rotate_extract_10_higher(a, b, data);
		extract_in_order(a, b, data);
	}
}

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
	organize(&a, &b, &data);
	return (0);
}

//read_stack(a, b);
