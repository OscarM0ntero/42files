/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/17 18:44:31 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_split
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

static void	ft_assign_coords(char const *str, size_t *strt, size_t *end, char c)
{
	size_t	s;
	size_t	e;

	e = *end;
	s = *end;
	while (str[s] == c && str[s])
		s++;
	e = s;
	while (str[e] != c && str[e])
		e++;
	*strt = s;
	*end = e;
}

static int	ft_assign_words(char const *s, char c, char **list, size_t n_words)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*word;

	i = 0;
	start = 0;
	end = 0;
	ft_assign_coords(s, &start, &end, c);
	while (i < n_words)
	{
		word = (char *)malloc((end - start) * sizeof(char));
		if (!word)
			return (1);
		word = ft_substr(s, start, end - start);
		list[i] = ft_strdup(word);
		free(word);
		ft_assign_coords(s, &start, &end, c);
		i++;
	}
	word = (char *)malloc(1 * sizeof(char));
	word = NULL;
	list[n_words] = word;
	free (word);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**list;

	if (!s)
		return (NULL);
	if (!c)
	{
		list = (char **)malloc(sizeof(char *));
		if (!list)
			return (NULL);
		*list = ft_strdup(s);
		return (list);
	}
	n_words = ft_count_words(s, c);
	list = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	if (ft_assign_words(s, c, list, n_words) || !list)
		return (NULL);
	return (list);
}

/* int	main(void)
{
	//char	str[] = "NrQg9t T7V EeHjY0PS8Cn Zx7wDMsT2gzvVi85l vWto 
	mxqLzQIe5sra3X2h lX847k Lm8yr O84SR bnYcxT0u6ADSfQ8I EKX l7fMHCbw1r 
	GcFB znfT6ICyJog4vwYeN IjTfwHL ZO9gDaoR";
	char	str[] = "\0aa\0bbb";
	size_t	i;
	char	**list;
	char	c;

	c = '\0';
	list = ft_split(str, c);
	i = 0;
	while (i < ft_count_words(str, c))
	{
		printf("Word %ld = %s$\n", i, list[i]);
		i++;
	}
} */
