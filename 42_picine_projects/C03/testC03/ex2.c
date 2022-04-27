/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:56:39 by omontero          #+#    #+#             */
/*   Updated: 2022/03/29 13:58:12 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	str1[] = "abcde";
	char	str2[] = "fghi";
	
	printf("%s\n", ft_strcat(str1, str2));
}