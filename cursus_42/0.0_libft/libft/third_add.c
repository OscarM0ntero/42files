/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/03 11:12:49 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_itoa
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

static char	*ft_assign_str(int n, char *s, int lenght, int is_neg)
{
	int	i;

	i = lenght - 1;
	if (n == -2147483648)
	{
		s = "-2147483648";
		return (s);
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
	return (s);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*s;
	int		is_neg;

	if (!n)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '0';
		return (s);
	}
	is_neg = 0;
	if (n < 0)
		is_neg++;
	length = ft_int_length(n) + is_neg;
	s = (char *)malloc((length) * sizeof(char));
	if (!(s))
		return (NULL);
	return (ft_assign_str(n, s, length, is_neg));
}

/* int	main(void)
{
	int	n;

	n = -2147483648;
	printf("Num. = %d$\n", n);
	printf("itoa = %s$\n", ft_itoa(n));
} */
