/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:32 by omontero          #+#    #+#             */
/*   Updated: 2022/06/01 18:06:43 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*ft_save_buffers(int fd, char *s)
{
	char	*buff;
	int		read_output;
	char	*c;

	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	read_output = 1;
	while (!ft_strchr(buff, '\n') && read_output != 0)
	{
		read_output = read(fd, buff, BUFFER_SIZE);
		if (!read_output)
			continue ;
		if (read_output == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_output] = 0;
		c = s;
		s = ft_strjoin(s, buff);
		free (c);
	}
	free (buff);
	return (s);
}

static char	*ft_set_next(char *s)
{
	size_t	i;
	char	*c;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n' && s[i + 1] != 0)
	{
		c = s;
		s = ft_strdup(&s[i + 1]);
		free (c);
	}
	else
	{
		free (s);
		s = NULL;
		return (s);
	}
	s[ft_strlen(s)] = 0;
	return (s);
}

static char	*ft_get_line(char *s)
{
	char	*line;
	size_t	i;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0 && s[fd] != NULL)
		free (s[fd]);
	s[fd] = ft_save_buffers(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = ft_get_line(s[fd]);
	if (!line)
	{
		free (s[fd]);
		return (NULL);
	}
	s[fd] = ft_set_next(s[fd]);
	if (s[fd] == NULL && line == NULL)
		return (NULL);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*c;

	fd = open("lines_around_10.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	close(fd);
	char	*temp;
	do
	{
		temp = get_next_line(fd);
		free (temp);
	} while (temp != NULL);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	fd = open("lines_around_10.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	c = get_next_line(fd);
	printf("fd  = >%s<\n", c);
	free (c);
	close(fd);
} */
