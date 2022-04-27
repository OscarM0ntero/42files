/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:55:20 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 17:55:20 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = c / *b;
	*b = c % *b;
}

int	main(void)
{
	int a;
	int b;

	a = 11;
	b = 5;

	ft_ultimate_div_mod(&a, &b);
	printf()
}