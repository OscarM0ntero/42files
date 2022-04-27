/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:49:55 by carmgarc          #+#    #+#             */
/*   Updated: 2022/04/06 16:30:17 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	word_size(int i, char *dic)
{
	int		len;
	int		fd;
	char	c;

	len = 0;
	fd = open(dic, O_RDONLY);
	if (fd == -1)
		return (0);
	while (i-- > 0)
		read(fd, &c, 1);
	while (read(fd, &c, 1) && c == ' ')
		;
	read(fd, &c, 1);
	while (read(fd, &c, 1) && c == ' ')
		;
	while (read(fd, &c, 1) && c != '\n')
		len++;
	return (len);
}

char	*find_word(int fd, int box_len, char c, char *dic)
{
	char	*str;
	int		i;
	int		word_len;

	word_len = word_size(box_len, dic);
	str = (char *)malloc(sizeof(char) * (word_len + 1));
	free(str);
	while (c == ' ')
		read(fd, &c, 1);
	read(fd, &c, 1);
	while (c == ' ')
		read(fd, &c, 1);
	i = 0;
	while (c != '\n')
	{
		str[i] = c;
		i++;
		read(fd, &c, 1);
	}
	str[i] = '\0';
	return (str);
}

char	*number_to_word(char *str, char *dic)
{
	int		fd;
	int		i;
	char	c;
	char	*word;

	fd = open(dic, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1))
	{
		if (str[i] != c && str[i] != '\0')
		{
			next_line(&fd, &i);
			continue ;
		}
		if ((c == ':' || c == ' ') && str[i] == '\0')
			word = find_word(fd, i, c, dic);
		else if (str[i] == '\0')
		{
			next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (word);
}
