/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_libc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/04/26 10:44:22 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != (char)c && *p)
		p++;
	if (*p != (char)c)
		p = NULL;
	return (p);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*i;
	char	*p;

	i = (char *)s;
	p = (char *)s;
	while (*i)
	{
		if (*i == (char)c)
			p = i;
		i++;
	}
	if (*p != (char)c)
		p = NULL;
	return (p);
}

// Nos sure if I have to control '\200' > '\0' case.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	n--;
	while (*p != (unsigned char)c && *p && n)
	{
		n--;
		p++;
	}
	if (*p != (unsigned char)c)
		p = NULL;
	return (p);
}
