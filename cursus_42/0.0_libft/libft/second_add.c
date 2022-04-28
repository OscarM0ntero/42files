/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/04/29 00:16:05 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_remfirst(const char *s, const char *set)
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

static char	*ft_remlast_str2_finder(char *str2, const char *set)
{
	int		cut;
	size_t	i;
	int		x;

	cut = 0;
	while (*str2 && !cut)
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
	str2 += 2;
	return (str2);
}

static char	*ft_remlast(const char *s, const char *set)
{
	char	*str;
	char	*str2;

	(void)str2;
	str = ft_strdup(s);
	str2 = &str[ft_strlen(str) - 1];
	str2 = ft_remlast_str2_finder(str2, set);
	*str2 = '\0';
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
	char	s1[] = "abaaaaabbcchola me llamo oscaraabcabbbccabcbc";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
}
