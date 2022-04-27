/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmgarc <carmgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:11:40 by carmgarc          #+#    #+#             */
/*   Updated: 2022/04/03 20:01:31 by carmgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	next_line(int *fd, int *i)
{
	char	c;
	int		flag;

	flag = 0;
	while (flag == 0 && read(*fd, &c, 1))
	{
		if (c == '\n')
			flag = 1;
	}
	*i = 0;
}

int	get_max_number_length(char *dic)
{
	int		i;
	int		maxlen;
	int		fd;
	char	c;

	maxlen = 0;
	i = -1;
	fd = open(dic, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1))
	{
		if (c == ' ' || c == ':')
		{
			if (i > maxlen)
				maxlen = i;
			next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (maxlen + 3);
}

int	check_number_length(int len, char *dic)
{
	int	maxlen;

	maxlen = get_max_number_length(dic);
	if (len > maxlen)
		return (-1);
	return (len);
}
