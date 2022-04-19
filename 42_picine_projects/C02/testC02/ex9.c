/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex9.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:54:56 by omontero          #+#    #+#             */
/*   Updated: 2022/03/28 13:57:41 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char text[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("Original: %s\n", text);
	printf("Con mayusculas al principio: %s\n", ft_strcapitalize(text));

	return (0);
}