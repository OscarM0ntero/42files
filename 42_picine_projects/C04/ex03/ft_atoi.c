/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:03:41 by omontero          #+#    #+#             */
/*   Updated: 2022/04/05 09:46:30 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	negativizador(int num, int x)
{
	if (x % 2 == 1)
	{
		num = num * -1;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	x;
	int	i;
	int	num;

	i = 0;
	num = 0;
	x = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			x++;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (negativizador(num, x));
}

#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	int		result;
	char	*str;
 
	str = " ---+--+ 1234ab567";
	result = ft_atoi(str);
	printf("%i", result);
}
