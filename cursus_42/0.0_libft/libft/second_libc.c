/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_libc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/05/13 13:42:38 by omontero         ###   ########.fr       */
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
	size_t			i;
	unsigned char	*c;

	c = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		c[i] = n;
		i++;
	}
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*c;
	const unsigned char	*s;

	if (!len || dest == src)
		return (dest);
	s = (const unsigned char *)src;
	c = (unsigned char *)dest;
	if (s < c)
		while (len--)
			*(c + len) = *(s + len);
	else
		while (len--)
			*c++ = *s++;
	return (dest);
}
