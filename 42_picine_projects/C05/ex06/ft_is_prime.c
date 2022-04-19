/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antrujil <antrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:36:14 by antrujil          #+#    #+#             */
/*   Updated: 2022/04/02 13:08:02 by antrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	cont;
	int	i;

	if (nb <= 1)
	{
		return (0);
	}
	else
	{
		i = 2;
		cont = 0;
		while (i <= nb / 2)
		{
			if (nb % i == 0)
			{
				cont++;
			}
			i++;
		}
		if (cont == 0)
			return (1);
		else
			return (0);
	}
}
