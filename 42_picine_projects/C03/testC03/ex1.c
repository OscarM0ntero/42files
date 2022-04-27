/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:39:58 by omontero          #+#    #+#             */
/*   Updated: 2022/03/29 13:40:25 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);


int	main(void)
{
	char	str1[] = "abcdfg";
	char	str2[] = "abcdef";
	
	printf("%d\n", ft_strncmp(str1, str2, 3));
	printf("%d\n", ft_strncmp(str1, str2, 5));
}
