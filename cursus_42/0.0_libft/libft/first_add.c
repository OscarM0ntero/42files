/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/17 18:09:15 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}

/* int	main(void)
{
	char	s1[] = "a";
	char	set[] = "a";

	printf("%s", ft_strtrim(s1, set));

	//printf("%s$", ft_substr(s1, 21, 4));
} */
