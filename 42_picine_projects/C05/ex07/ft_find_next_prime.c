/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:36:14 by antrujil          #+#    #+#             */
/*   Updated: 2022/04/05 18:08:50 by omontero         ###   ########.fr       */
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
		while (i <= nb / 2 && i < 46341)
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

int	ft_find_next_prime(int nb)
{
	int	aux;

	aux = nb;
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(aux))
		aux++;
	return (aux);
}
