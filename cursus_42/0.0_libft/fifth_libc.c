/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth_libc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/04/26 10:32:45 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_little(char *p, const char *little, const size_t len)
{
	size_t	x;
	size_t	i;
	int		tmp;

	x = (size_t)len;
	i = 0;
	tmp = 0;
	while (little[i] && x)
	{
		if (p[i] != little[i])
			tmp = 1;
		i++;
		x--;
	}
	if (!little[i])
		return (tmp);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*p;

	p = (char *)big;
	if (*little == '\0')
		return (p);
	while (*p && len)
	{
		if (*p == *little)
		{
			if (!ft_check_little(p, little, len))
				return (p);
		}
		len--;
		p++;
	}
	return (NULL);
}

/* ************************************************* */
// Atoi malo, arreglar || Maybe already fixed -> To check
static int	ft_neg(int num, int x)
{
	if (x % 2 == 1)
	{
		num = num * -1;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	x;
	int	i;
	int	num;

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
	return (ft_neg(num, x));
}
