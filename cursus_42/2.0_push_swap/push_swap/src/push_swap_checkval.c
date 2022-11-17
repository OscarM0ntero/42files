/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/17 13:28:44 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Acabar el atoi long para escanear los limites del int y ver que no se pase
//	y comprobar repetidos con una funcion nueva

static long	ft_neg(long num, int x)
{
	if (x % 2 == 1)
	{
		num = num * -1;
	}
	return (num);
}

long	ft_atoi_long(const char *nptr, t_data *data)
{
	int			x;
	int			i;
	long		num;

	i = 0;
	num = 0;
	x = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			x++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	if (ft_neg(num, x) > 2147483647 || ft_neg(num, x) < -2147483648)
		data->error = 1;
	return (ft_neg(num, x));
}

int	ft_check_rep(t_stack *a, t_data *data)
{
	int		i;
	char	*s;
	char	*tmp;

	i = 0;
	s = ft_strdup("");
	while (i < data->total_amount_of_numbers)
	{
		tmp = ft_strjoin("|", ft_itoa(a->stk[i].val));
		tmp = ft_strjoin(tmp, "|");
		if (ft_strnstr(s, tmp, ft_strlen(s)))
			return (free(tmp), free(s), 1);
		s = ft_strjoin(s, tmp);
		i++;
		free(tmp);
	}
	free(s);
	return (0);
}
