/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:27:24 by omontero          #+#    #+#             */
/*   Updated: 2022/03/29 13:40:30 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	str1[] = "abcdfg";
	char	str2[] = "abcdef";
	
	printf("%d\n", ft_strcmp(str1, str2));
}
