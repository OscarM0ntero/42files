/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/03 00:18:01 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strtrim(const char *s1, char const *set)
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
} */

/* int	main(void)
{
	char	s1[] = "abcacb hola abbcaabc";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
} */
