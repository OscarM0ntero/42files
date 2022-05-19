/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/18 09:30:51 by omontero         ###   ########.fr       */
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
		is_neg--;
	length = ft_int_length(n) + is_neg + 1;
	s = (char *)malloc((length) * sizeof(char));
	if (!(s))
		return (NULL);
	ft_assign_str(n, s, length, is_neg);
	s[ft_int_length(n) + 1] = '\0';
	return (s);
}

/* int	main(void)
{
	int	n;

	n = -5859;
	printf("Num. = %d$\n", n);
	printf("itoa = %s$\n", ft_itoa(n));
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	p = ft_strdup(s);
	if (!p)
		return (p = NULL);
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}
