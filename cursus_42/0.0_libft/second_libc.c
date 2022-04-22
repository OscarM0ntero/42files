/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_libc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/04/21 19:17:31 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_memset(void *p, int n, size_t len)
{
	size_t	i;
	size_t	j;

	j = ft_strlen((char *)p);
	i = 0;
	while (i < len && i < j)
	{
		((char *)p)[i] = (char)c;
		i++;
	}
	return (p);
}

void	bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*memcpy(void *dest, const void *src, size_t n)
{
	
}
