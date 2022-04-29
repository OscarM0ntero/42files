/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/04/29 13:17:49 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	*ft_remfirst(const char *s, const char *set)
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

static char	*ft_remlast_end_finder(char *str2, const char *set)
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

	str = ft_strdup(s);
	str2 = &str[ft_strlen(str) - 1];
	str2 = ft_remlast_end_finder(str2, set);
	ft_bzero(str2, ft_strlen(str2));
	return (ft_strdup(str));
} */

char	*ft_strtrim(const char *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]))
		end--;
	str = ft_substr(s1, start + 1, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}

int	main(void)
{
	char	s1[] = "abcacbhola abbcaabc";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
}
