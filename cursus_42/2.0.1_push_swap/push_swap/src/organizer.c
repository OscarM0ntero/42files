/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/08/13 18:29:31 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*/
void	ft_main_organizer(t_game g)
{
	static int	n;
	int			i;
	size_t		val;

	if (!n)
		n = 0;
	i = 0;
	while (!ft_b_in_order(g) && g.a.size)
		if (g.a.stk[i].val >= (n + 0) && g.a.stk[i].val < (n + 10))
		{
			//	No se que hacer aqui la verdad -_-
			val = g.a.stk[i].val;
			i = 0;
			while  
		}
		else
		{
			i++;
		}
	}
	n += 10;
	return (g);
}
