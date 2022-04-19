/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:12:01 by carmgarc          #+#    #+#             */
/*   Updated: 2022/04/06 16:22:29 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	remove_initial_zeros(char **str)
{
	char	*number;
	int		i;
	int		j;

	number = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	free(number);
	i = 0;
	j = 0;
	while ((*str)[i] == '0')
		i++;
	while ((*str)[i] != '\0')
	{
		number[j] = (*str)[i];
		i++;
		j++;
	}
	if (j == 0)
	{
		number[j] = '0';
		j++;
	}
	number[j] = '\0';
	*str = number;
}

void	divide_number(int *i, char *str, char *argv, int *l)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	if (*i % 3 != 0)
	{
		while (*i % 3 != 0)
		{
			str[k] = argv[*l];
			(*i)--;
			move_index(&k, l);
		}
	}
	else
	{
		while (j < 3)
		{
			str[k] = argv[*l];
			j++;
			move_index(&k, l);
		}
	}
	str[k] = '\0';
}

int	check_string(int argc, char **argv, char *dic)
{
	int	i;

	if (argc == 1 || argc > 3)
		return (-1);
	i = 0;
	if (argv[1][0] == '0')
		remove_initial_zeros(&argv[1]);
	if (argv[1][0] == '\0')
		return (-1);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (-1);
		i++;
	}
	i = check_number_length(i, dic);
	return (i);
}

void	print_words(int i, char *input, char *str, char *dic)
{
	int	actual_box;
	int	n_boxes;
	int	l;

	l = 0;
	actual_box = i / 3;
	if (i % 3 != 0)
		actual_box++;
	n_boxes = actual_box;
	while (actual_box != 0)
	{
		divide_number(&i, str, input, &l);
		if (actual_box != n_boxes && ft_strcmp(str, "000") != 0)
			write(1, ", ", 2);
		if (actual_box == 1 && ft_strcmp(str, "000")
			!= 0 && str[0] == '0' && n_boxes != 1)
			write(1, "and ", 4);
		print_number(str, dic);
		if (ft_strcmp(str, "000") != 0 && actual_box != 1)
			print_between(actual_box, dic);
		actual_box--;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*input;
	char	*dic;

	dic = NULL;
	input = NULL;
	if (argc == 2)
	{
		dic = "numbers.dict";
		input = argv[1];
	}
	else if (argc == 3)
	{
		dic = argv[1];
		input = argv[2];
	}
	i = check_string(argc, argv, dic);
	if (i == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * 4);
	print_words(i, input, str, dic);
}
