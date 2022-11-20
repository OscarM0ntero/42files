/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/11/20 08:17:06 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (nptr[i] || ft_neg(num, x) > 2147483647 || ft_neg(num, x) < -2147483648)
		data->error = 1;
	return (ft_neg(num, x));
}

char	*ft_strjoin_box(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = (char *)malloc((size + 1) * sizeof(char));
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '|';
	j = 0;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '|';
	str[size] = 0;
	return (str);
}

int	ft_check_rep(t_stack *a, t_data *data)
{
	int		i;
	char	*s;
	char	*tmp;
	char	*leaks;
	char	*c;

	i = -1;
	s = ft_strdup("");
	while (i++ < data->total_amount_of_numbers - 1)
	{
		tmp = ft_strdup("");
		leaks = tmp;
		c = ft_itoa(a->stk[i].val);
		tmp = ft_strjoin_box("", c);
		free (c);
		free (leaks);
		if (ft_strnstr(s, tmp, ft_strlen(s)))
			return (free(tmp), free(s), 1);
		leaks = s;
		s = ft_strjoin(s, tmp);
		free (leaks);
		free(tmp);
	}
	free(s);
	return (0);
}
