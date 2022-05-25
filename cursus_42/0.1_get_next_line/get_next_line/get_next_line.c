/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:32 by omontero          #+#    #+#             */
/*   Updated: 2022/05/25 12:27:10 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// "hola me llamo oscar \nque pasa por aqui?"
static char	*ft_save_buffers(int fd, char *s)
{
	char	*buff;
	int		read_output;

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
		//if (read_output > 0)
		//{
		//buff[read_output] = 0;
		s = ft_strjoin(s, buff);
		//}
	}
	free (buff);
	return (s);
}
//fallo ultima linea

static char	*ft_set_next(char *s, int last_line)
{
	size_t	i;

	if (!last_line)
	{
		i = 0;
		while (s[i] != '\n' && s[i])
			i++;
		i++;
		s = ft_substr(s, i, ft_strlen(s) - i);
	}
	else
		s = "";
	if (!s)
		return (NULL);
	s[ft_strlen(s)] = 0;
	return (s);
}

static char	*ft_get_line(char *s, int *last_line)
{
	char	*line;
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		i++;
		line = ft_substr(s, 0, i);
	}
	else if (!s[i])
	{
		//i++;
		line = ft_substr(s, 0, i);
		*last_line = 1;
	}
	//printf("-%s+", line);
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
		return (NULL);
	line = ft_get_line(s, &last_line);
	if (!line)
		return (NULL);
	//printf("-%s+", line);
	s = ft_set_next(s, last_line);
	//printf("-%d+", last_line);
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
	while (i < 8)
	{
		printf(">%s<\n", get_next_line(fd));
		i++;
	}
	close(fd);
}
