/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/03 01:05:22 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int	main(void)
{
	char	s1[] = "abcacb hola abbcaabc";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
} */

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	n_words;

	n_words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
			n_words++;
		while (s[i] == c && s[i])
			i++;
	}
	return (n_words);
}

static void	ft_assign_next_coords(char const *s, size_t *start, size_t *end, char c)
{
	*start = *end;
	while (s[*start] == c && s[*start])
		start++;
	*end = *start;
	while (s[*end] != c && s[*end])
		end++;
}
// "  hola soy  oscar "
static int	ft_assign_words(char const *s, char c, char **list, size_t n_words)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*word;

	i = 0;
	start = 0;
	end = 0;
	ft_assign_next_coords(s, &start, &end, c);
	while (i < n_words)
	{
		word = (char *)malloc((end - start) * sizeof(char));
		if (!word)
			return (1);
		word = ft_substr(s, start, end - start);
		list[i] = word;
		free(word);
		ft_assign_next_coords(s, &start, &end, c);
		i++;
	}
	word = (char *)malloc(1 * sizeof(char));
	word = NULL;
	list[n_words] = word;
	free (word);
	return (0);
}
// " hola  soy oscar"
char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**list;

	n_words = ft_count_words(s, c);
	list = (char **)malloc((n_words + 1) * sizeof(char *));
	if (ft_assign_words(s, c, list, n_words) || !list)
		return (NULL);
	return (list);
}

int	main(void)
{
	char	str[] = " hola soy oscar  ";

	printf("%s\n", ft_split(str, ' ')[0]);
}
// Deberia funcionar, toca depurar errores (Seg. Fault)