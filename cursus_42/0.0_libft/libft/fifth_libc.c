/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth_libc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/05/17 18:10:00 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ss1 != *ss2)
			return ((int)(*ss1 - *ss2));
		ss1++;
		ss2++;
	}
	return (0);
}

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
	int			x;
	int			i;
	long int	num;

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
