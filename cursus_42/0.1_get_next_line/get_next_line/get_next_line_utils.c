/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/05/25 14:38:11 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	if ((nmemb >= SIZE_MAX && size > 1) || (size >= SIZE_MAX && nmemb > 1))
		return (NULL);
	p = (void *)malloc(nmemb * size);
	if (!p)
	{
		free (p);
		return (NULL);
	}
	while (i < nmemb * size)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}

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

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	p = (char *)ft_calloc(len, sizeof(char));
	if (!p)
		return (NULL);
	if (!p && !s1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = ((char *)s1)[i];
		i++;
	}
	return (p);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	return (str);
}

//extra

static void	ft_assign_i(char const *s, size_t *i, size_t len)
{
	*i = len;
	if (len > ft_strlen(s))
		*i = ft_strlen(s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = (char *)ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	ft_assign_i(s, &i, len);
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
