/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antrujil <antrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:36:14 by antrujil          #+#    #+#             */
/*   Updated: 2022/04/02 11:56:36 by antrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	cont;

	res = 1;
	cont = 1;
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		while (cont <= nb)
		{
			res *= cont;
			cont++;
		}
	}
	return (res);
}
