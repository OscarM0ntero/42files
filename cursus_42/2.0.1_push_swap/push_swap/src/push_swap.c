/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/03 21:05:41 by oscar            ###   ########.fr       */
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

//	Devuelve la posicion del numero que hay 10 veces menor encontrado, o -1
int	search_num_10_under(int num, t_stack *a, t_data *data)
{
	int	i;
	int	j;
	int	numbers_found;
	int	pos;

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

void	rotate_extract_10_higher(t_stack *a, t_stack *b, t_data *data)
{
	int	i;
	int	n_extracted;
	int	low;

	n_extracted = 0;
	low = a->stk[search_num_10_under(data->highest_number_disordered, a, data)].val;
	i = 0;
	while (i < data->total_amount_of_numbers && n_extracted < 10)
	{
		if (a->stk[0].val >= low)
		{
			ft_pb(a, b);
			n_extracted++;
		}
		else
			ft_ra(a, 1);
		//read_stack(*a, *b);
		//printf("x%d\n", n_extracted);
		i++;
	}
}

void	organize(t_stack *a, t_stack *b, t_data *data)
{
	//int	i;

	//i = data->highest_number;
	/*while (data->numbers_in_order != data->total_amount_of_numbers && i > data->lowest_number)
	{
		read_stack(*a, *b);
		printf("i: %d\n", i);
		rotate_extract_10_higher(a, b, data);
		
		i--;
	}*/
	rotate_extract_10_higher(a, b, data);
	read_stack(*a, *b);
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
	data.highest_number_disordered = data.highest_number;
	read_stack(a, b);
	organize(&a, &b, &data);
	return (0);
}
