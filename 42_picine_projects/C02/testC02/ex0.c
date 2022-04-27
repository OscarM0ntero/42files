/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:58:56 by omontero          #+#    #+#             */
/*   Updated: 2022/03/23 17:30:46 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_strcpy(int *dest, int *src);

int	main(void)
{
	char	*palabra;
	char	*dest;
	
	palabra = "Mario";
	printf("Source: %s\n", palabra);
	printf("Copy: %s", ft_strcpy(dest, palabra));
}
