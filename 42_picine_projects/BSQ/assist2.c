/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:34:39 by omontero          #+#    #+#             */
/*   Updated: 2022/04/07 14:43:13 by omontero         ###   ########.fr       */
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

int	ft_check_all_matrix_lines(char *argv, struct s_parameters *param, int i)
{
	int		j;
	int		k;
	int		fd;
	char	c;

	k = 1;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1) && c != '\n')
		;
	while (read(fd, &c, 1) && c != '\n')
		;
	while (k < param->height - 1)
	{
		j = 0;
		k++;
		while (read(fd, &c, 1) && c != '\n')
			j++;
		if (j != i)
		{
			close (fd);
			return (-1);
		}
	}
	close (fd);
	return (i);
}

// Return matrix width if all matrix lines are the same, if not, returns -1 
int	ft_extract_width(char *argv, struct s_parameters *param)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1) && c != '\n')
		;
	while (read(fd, &c, 1) && c != '\n')
		i++;
	close (fd);
	i = ft_check_all_matrix_lines(argv, param, i);
	return (i);
}

int	ft_check_height(char *argv, struct s_parameters *param)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	close (fd);
	if (param->height != i)
		return (-1);
	return (i);
}

void	ft_assign_things(struct s_parameters *param, char *str)
{
	param->gen = str[0];
	param->obs = str[1];
	param->sus = str[2];
}
