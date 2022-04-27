/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:43:34 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 18:45:13 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);

int	main(void)
{
	char	str[] = "Mario manda";
	char	*p_str;
	int		count = ft_strlen(str);

	p_str = str;
	ft_putstr(p_str);
	printf(" -> %d", count);
}
