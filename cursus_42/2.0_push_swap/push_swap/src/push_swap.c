/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/17 14:09:55 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Esta funcion asigna los valores introduciodos por consola
//	al stack A de inicio :)

int	assign_values(char **argv, t_stack *a, t_data *data)
{
	int	i;

	i = 0;
	a->size = data->total_amount_of_numbers;
	a->stk = ft_calloc(a->size, sizeof(t_value));
	while (i < data->total_amount_of_numbers)
	{
		if (!(argv[i + 1][0] >= 48 && argv[i + 1][0] <= 57) && !((argv[i
					+ 1][0] == '-') && (argv[i + 1][1] >= 48 && argv[i
					+ 1][1] <= 57)))
			return (1);
		a->stk[i].val = ft_atoi_long(argv[i + 1], data);
		if (data->error)
			return (1);
		a->stk[i].pos = i;
		i++;
	}
	return (0);
}

void	organize_2(t_stack *a, t_data *data)
{
	if (a->stk[0].val > a->stk[1].val)
		ft_sa(a, 1);
	data->numbers_in_order = 2;
	data->highest_number_dis = search_lower(*a);
	data->lowest_number_ord = data->highest_number_dis;
}

//	Devuelve 1 si A esta ordenado, 2 si hay orden pero empieza en medio,
//	0 si no hay orden
int	order(t_stack *a)
{
	int	i;
	int	j;
	int	x;

	if ((search_num_pos(*a, search_lower(*a)) != 0 && search_higher_pos(*a)
			!= search_num_pos(*a, search_lower(*a)) - 1) || (search_num_pos(*a,
				search_lower(*a)) == 0 && search_higher_pos(*a) != a->size - 1))
		return (0);
	else
	{
		i = a->size;
		j = search_num_pos(*a, search_lower(*a));
		while (i--)
		{
			x = 1;
			if (j == a->size - 1)
				x = -(a->size - 1);
			if (a->stk[j].val > a->stk[j + x].val && a->stk[j].val != s_h(*a))
				return (0);
			j += x;
		}
	}
	if (search_num_pos(*a, search_lower(*a)) == 0)
		return (1);
	return (2);
}

void	organize(t_stack *a, t_stack *b, t_data *data)
{
	if (order(a) == 1)
		return ;
	else if (order(a) == 2)
		order_a(a, data);
	else
	{
		while (data->total_amount_of_numbers != data->numbers_in_order
			&& order(a) != 1)
		{
			if (order(a) == 2)
				order_a(a, data);
			else if (data->total_amount_of_numbers == 2)
				organize_2(a, data);
			else
			{
				rotate_extract_x_higher(a, b, data);
				extract_in_order(a, b, data);
			}
		}
	}
}

//	Hacer free en cada instruccion como he hecho en PUSH y seguir con memdetect
int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_data	data;
	int		argc = 4;
	char	**argv;

	argv = ft_calloc(5, sizeof(char *));
	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("7");
	argv[2] = ft_strdup("5");
	argv[3] = ft_strdup("4");
	data.error = 0;
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
	if (assign_values(argv, &a, &data) || ft_check_rep(&a, &data))
		return (write(1, "Error\n", 6));
	data.highest_number = s_h(a);
	data.lowest_number = search_lower(a);
	data.highest_number_dis = data.highest_number;
	data.lowest_number_ord = data.highest_number;
	organize(&a, &b, &data);
	free (argv[0]);
	free (argv[1]);
	free (argv[2]);
	free (argv[3]);
	free (argv);
	return (0);
}

//read_stack(a, b);
