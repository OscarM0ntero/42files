/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:30:49 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 18:31:23 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);

int	main(void)
{
	char	str[] = "Hello, world!";
	char	*p_str;

	p_str = str;
	ft_putstr(p_str);
}
