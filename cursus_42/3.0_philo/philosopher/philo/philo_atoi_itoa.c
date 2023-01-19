/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/19 13:55:22 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static	int	ft_int_length(int n)
{
	size_t	i;
	int		j;

	i = 1;
	j = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (i <= (size_t)n)
	{
		i *= 10;
		j++;
	}
	return (j);
}

static void	ft_assign_str(int n, char *s, int lenght, int is_neg)
{
	int	i;

	i = lenght - 2;
	if (n == -2147483648)
	{
		while (i >= is_neg)
		{
			s[i] = (n % 10) * -1 + 48;
			n /= 10;
			i--;
		}
		s[0] = '-';
		return ;
	}
	if (n < 0)
		n *= -1;
	while (i >= is_neg)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	if (is_neg)
		s[0] = '-';
}

char	*ft_itoa(int n)
{
	int		length;
	char	*s;
	int		is_neg;

	if (n == 0)
	{
		s = (char *)malloc(2 * sizeof(char));
		if (!s)
			return (NULL);
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	is_neg = 1;
	if (n >= 0)
		is_neg = 0;
	length = ft_int_length(n) + is_neg + 1;
	s = (char *)malloc((length) * sizeof(char));
	if (!(s))
		return (NULL);
	ft_assign_str(n, s, length, is_neg);
	s[ft_int_length(n) + is_neg] = '\0';
	return (s);
}
