/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/02 02:08:46 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Esta funcion asigna los valores introduciodos por consola
//	al stack A de inicio :)

void	assign_values(char ***argv, t_stack *a, t_data data)
{
	int	i;

	i = 0;
	a->size = data.total_amount_of_numbers;
	a->stk = ft_calloc(a->size, sizeof(t_value));
	while (i < data.total_amount_of_numbers)
	{
		a->stk[i].val = ft_atoi(argv[i + 1]);
		a->stk[i].pos = i + 1;
		i++;
	}
}

//	Esta funcion simplemente imprime por pantalla el stack que le pasemos
void	read_stack(t_stack x)
{
	int	i;

	i = 0;
	while (i < x.size)
	{
		printf("Pos: %d		Value: %d\n", x.stk[i].val, x.stk[i].val);
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

t_stack	organize(t_stack a, t_stack b, t_data data)
{
	while (data.lowest_number_in_order != data.lowest_number)
	{
	}
	return (a);
}

//	./push_swap <nums separados por ' '>
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	data.total_amount_of_numbers = argc - 1;
	data.numbers_in_order = 0;
	//	Asignamos los valores al stack A
	assign_values(argc, *argv, *a, data);
	read_stack(a);
	data.highest_number = search_higher(a);
	data.lowest_number = search_lower(a);
	data.lowest_number_in_order = data.highest_number;
	a = organize(a, b, data);
	return (0);
}
