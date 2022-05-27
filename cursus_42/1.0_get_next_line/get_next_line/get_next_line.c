/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:32 by omontero          #+#    #+#             */
/*   Updated: 2022/05/27 13:53:26 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (read_output == -1)
		{
			free (buff);
			return (NULL);
		}
		if (read_output != 0)
		{
			c = s;
			s = ft_strjoin(s, buff);
			free (c);
		}
	}
	free (buff);
	return (s);
}

static char	*ft_set_next(char *s, int last_line)
{
	size_t	i;
	char	*c;

	if (!last_line)
	{
		c = s;
		i = 0;
		while (s[i] != '\n' && s[i])
			i++;
		i++;
		s = ft_strdup(&s[i]);
		free (c);
	}
	else
	{
		free(s);
		s = NULL;
		return (s);
	}
	if (!s)
		return (NULL);
	s[ft_strlen(s)] = 0;
	return (s);
}

static char	*ft_get_line(char *s, int *last_line)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		i++;
		line = ft_calloc(i + 1, sizeof(char));
		while (++j < i && s[j + 1])
			line[j] = s[j];
		line[j] = 0;
	}
	else
	{
		i++;
		line = ft_strdup(s);
		*last_line = 1;
	}
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			last_line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_line = 0;
	s = ft_save_buffers(fd, s);
	if (!s)
	{
		free (s);
		return (NULL);
	}
	line = ft_get_line(s, &last_line);
	if (!line)
	{
		free (s);
		return (NULL);
	}
	s = ft_set_next(s, last_line);
	if (s == NULL && line[0] == 0)
		return (NULL);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 10)
	{
		printf(">%s<\n", get_next_line(fd));
		i++;
	}
	close(fd);
}