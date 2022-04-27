/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex7.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:56:39 by omontero          #+#    #+#             */
/*   Updated: 2022/03/28 13:48:36 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char text[] = "abCdE fgHi JklMnop qRStUV Wxyz áéíóú";

	printf("Original: %s\n", text);
	printf("Con mayusculas: %s\n", ft_strupcase(text));

	return (0);
}
