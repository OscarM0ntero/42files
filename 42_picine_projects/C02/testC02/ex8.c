/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex8.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:56 by omontero          #+#    #+#             */
/*   Updated: 2022/03/23 12:17:56 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char text[] = "abCdE fgHi JklMnop qRStUV Wxyz áéíóú";

	printf("Original: %s\n", text);
	printf("Con minusculas: %s\n", ft_strlowcase(text));

	return (0);
}