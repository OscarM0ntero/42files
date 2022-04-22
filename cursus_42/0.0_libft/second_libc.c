/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_libc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/04/22 12:18:45 by omontero         ###   ########.fr       */
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
		((char *)p)[i] = (char)n;
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

	if (!dest)
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
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

int main(void)
{
	char   csrc[100] = "Geeksfor";
    printf("%lu ", ft_strlen(csrc) + 1);
    printf("%s ", csrc + 5);
    memmove(csrc + 5, csrc, ft_strlen(csrc) + 1);
    printf("%s", csrc);
	return 0;
}