/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:09:30 by omontero          #+#    #+#             */
/*   Updated: 2022/03/23 10:02:40 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int	*********p_nbr;
	int	********p_nbr2;
	int	*******p_nbr3;
	int	******p_nbr4;
	int	*****p_nbr5;
	int	****p_nbr6;
	int	***p_nbr7;
	int	**p_nbr8;
	int	*p_nbr9;
	int	nbr;

	nbr = 7;
	p_nbr9 = &nbr;
	p_nbr8 = &p_nbr9;
	p_nbr7 = &p_nbr8;
	p_nbr6 = &p_nbr7;
	p_nbr5 = &p_nbr6;
	p_nbr4 = &p_nbr5;
	p_nbr3 = &p_nbr4;
	p_nbr2 = &p_nbr3;
	p_nbr = &p_nbr2;
	ft_ultimate_ft(p_nbr);
	printf("Esto debe ser 42 -> %d", nbr);
	return (0);
}
