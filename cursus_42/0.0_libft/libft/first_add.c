/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/04/28 19:39:55 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i - 1];
		i++;
	}
	str[i] = '\0';
	return (str);
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
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	return (str);
}
*/

// Funciones auxiliares de ft_strtrim
/*
int	main(void)
{
	char	s1[] = "cabdhola me llamo oscar";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
}
*/
char	*ft_remfirst(const char *s, const char *set)
{
	char	*str;
	int		x;
	int		cut;
	size_t	i;

	cut = 0;
	str = ft_strdup(s);
	while (*str && !cut)
	{
		i = 0;
		x = 0;
		while (i < ft_strlen(set) && !x)
		{
			if (*str == set[i])
				x = 1;
			i++;
		}
		if (!x)
			cut = 1;
		str++;
	}
	str--;
	return (ft_strdup(str));
}

char	*ft_remlast(const char *s, const char *set)
{
	char	*str;
	char	*str2;
	int		x;
	int		cut;
	size_t	i;

	str = ft_strdup(s);
	str2 = &str[ft_strlen(str) - 1];
	cut = 0;
	printf("%c", str[1]);
	while (*str && !cut)
	{
		i = 0;
		x = 0;
		while (i < ft_strlen(set) && !x)
		{
			if (*str2 == set[i])
				x = 1;
			i++;
		}
		if (!x)
			cut = 1;
		str2--;
	}
	str2++;
	str2 = '\0';
	str
	return (ft_strdup(str));
}

char	*ft_strtrim(const char *s1, char const *set)
{
	char	*str;

	str = ft_remfirst(s1, set);
	str = ft_remlast(str, set);

	if (!str)
		return (NULL);
	return (str);
}

int	main(void)
{
	char	s1[] = "abchola me llamo oscarabc";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
}
