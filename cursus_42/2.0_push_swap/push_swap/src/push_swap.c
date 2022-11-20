/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/20 08:04:27 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Esta funcion asigna los valores introduciodos por consola
//	al stack A de inicio :)
/**
 * 
*/
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

// 63 89 94 55 31 54 36 39 33 60 27 76 3 17 88 0 67 22 25 64
//	Hacer free en cada instruccion como he hecho en PUSH y seguir con memdetect
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

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
		return (free (a.stk), free (b.stk), write(1, "Error\n", 6));
	data.highest_number = s_h(a);
	data.lowest_number = search_lower(a);
	data.highest_number_dis = data.highest_number;
	data.lowest_number_ord = data.highest_number;
	organize(&a, &b, &data);
	return (free(a.stk), free(b.stk), 0);
}

//read_stack(a, b);
/*

int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_data	data;
	int		argc = 21;
	char	**argv;

	argv = ft_calloc(21, sizeof(char *));
	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("63");
	argv[2] = ft_strdup("89");
	argv[3] = ft_strdup("94");
	argv[4] = ft_strdup("55");
	argv[5] = ft_strdup("31");
	argv[6] = ft_strdup("54");
	argv[7] = ft_strdup("36");
	argv[8] = ft_strdup("39");
	argv[9] = ft_strdup("33");
	argv[10] = ft_strdup("60");
	argv[11] = ft_strdup("27");
	argv[12] = ft_strdup("76");
	argv[13] = ft_strdup("3");
	argv[14] = ft_strdup("17");
	argv[15] = ft_strdup("88");
	argv[16] = ft_strdup("0");
	argv[17] = ft_strdup("67");
	argv[18] = ft_strdup("22");
	argv[19] = ft_strdup("25");
	argv[20] = ft_strdup("64");
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
	{
		free (argv[0]);
		free (argv[1]);
		free (argv[2]);
		free (argv[3]);
		free (argv[4]);
		free (argv[5]);
		free (argv[6]);
		free (argv[7]);
		free (argv[8]);
		free (argv[9]);
		free (argv[10]);
		free (argv[11]);
		free (argv[12]);
		free (argv[13]);
		free (argv[14]);
		free (argv[15]);
		free (argv[16]);
		free (argv[17]);
		free (argv[18]);
		free (argv[19]);
		free (argv[20]);
		free (argv[21]);
		free (argv);
		free (a.stk);
		free (b.stk);
		return (write(1, "Error\n", 6));
	}
	data.highest_number = s_h(a);
	data.lowest_number = search_lower(a);
	data.highest_number_dis = data.highest_number;
	data.lowest_number_ord = data.highest_number;
	organize(&a, &b, &data);
	free (argv[0]);
	free (argv[1]);
	free (argv[2]);
	free (argv[3]);
	free (argv[4]);
	free (argv[5]);
	free (argv[6]);
	free (argv[7]);
	free (argv[8]);
	free (argv[9]);
	free (argv[10]);
	free (argv[11]);
	free (argv[12]);
	free (argv[13]);
	free (argv[14]);
	free (argv[15]);
	free (argv[16]);
	free (argv[17]);
	free (argv[18]);
	free (argv[19]);
	free (argv[20]);
	free (argv[21]);
	free (argv);
	free (a.stk);
	free (b.stk);
	return (0);
}

//read_stack(a, b);


*/