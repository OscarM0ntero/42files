/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:32 by omontero          #+#    #+#             */
/*   Updated: 2022/05/24 10:48:07 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(count * size);
	if (str == 0)
		return (0);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

// "hola me llamo oscar \nque pasa por aqui?"
static char	*ft_save_buffers(int fd, char *s, int *read_output)
{
	char	*buff;

	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, '\n') && read_output != 0)
	{
		*read_output = read(fd, buff, BUFFER_SIZE);
		if (*read_output == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[*read_output] = 0;
		s = ft_strjoin(s, buff);
	}
	free (buff);
	return (s);
}

static char	*ft_get_line(char *s)
{
	char	*line;
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != EOF && s[i])
		i++;
	if (s[i] == '\n')
	{
		i++;
		line = ft_substr(s, 0, i);
	}
	else if (s[i] == EOF)
	{
		printf("xd");
		i++;
		line = ft_substr(s, 0, i);
	}
	return (line);
}

static char	*ft_set_s(char *s, size_t line_len, int read_output)
{
	size_t	i;

	if (read_output > 0)
	{
		s = ft_substr(s, line_len, read_output - line_len);
		if (!s)
			return (NULL);
	}
	else if (read_output == 0) //no se... sigue por aqui...
	{
		i = 0;
		while (s[i] != '\n' && s[i] != EOF && s[i])
			i++;
		if (s[i] == EOF)
		{
			free (s);
			return (NULL);
		}
		s = ft_substr(s, line_len, ft_strlen(s) - line_len);
		if (!s)
			return (NULL);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			read_output;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_output = 1;
	s = ft_save_buffers(fd, s, &read_output);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	if (!line)
		return (NULL);
	s = ft_set_s(s, ft_strlen(line), read_output);
	printf(">%s<", s);
	if (!s)
		return (NULL);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 6)
	{
		//printf("%d -> ", fd);
		printf("|%s|", get_next_line(fd));
		i++;
	}
	close(fd);
}
