/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:37 by pecampos          #+#    #+#             */
/*   Updated: 2022/04/07 17:30:03 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

struct		s_parameters
{
	int		height;
	int		width;
	int		tam_square;
	char	gen;
	char	obs;
	char	sus;
	char	**mat;
};
//454123

void	ft_core(char *argv, struct s_parameters *param)
{
	ft_matrix_assign(argv, param);
	while (param->tam_square > 0 && ft_move_square(param) == 0)
	{
		param->tam_square--;
	}
	ft_write_square(param, ft_move_square2(param));
}

void	ft_assign_from_file(char *argv, struct s_parameters *param)
{
	int		fd;
	int		i;
	char	c;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1) && c != '\n')
	{
		i++;
	}
	close (fd);
	str = (char *)malloc(i * sizeof(char));
	i = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1) && c != '\n')
	{
		str[i] = c;
		i++;
	}
	close (fd);
	param->height = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	ft_assign_things(param, str);
}

int	ft_assign_param(struct s_parameters *param, char *argv)
{
	ft_assign_from_file(argv, param);
	param->width = ft_extract_width(argv, param);
	if (param->width == -1)
		return (-1);
	else if (param->height != ft_check_height(argv, param))
		return (-1);
	if (param->width <= param->height)
		param->tam_square = param->width;
	else
		param->tam_square = param->height;
	return (0);
}

int	ft_check_error(int e)
{
	if (e != 0)
	{
		if (e == -1)
			ft_putstr("map error");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_parameters	param;
	int					error;
	int					i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			error = ft_assign_param(&param, argv[i]);
			ft_assign_matrix_size(&param);
			if (ft_check_error(error))
			{
				i++;
				continue ;
			}
			ft_core(argv[i], &param);
			ft_print_matrix(&param);
			free (param.mat);
			i++;
		}
	}
	return (0);
}
