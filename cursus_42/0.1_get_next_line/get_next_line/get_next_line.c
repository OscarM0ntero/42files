/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:32 by omontero          #+#    #+#             */
/*   Updated: 2022/05/23 10:56:30 by omontero         ###   ########.fr       */
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
		buff[read_output] = 0;
		s = ft_strjoin(s, buff);
	}
	free (buff);
	return (s);
}

static char	*ft_get_line(char *s)
{
	char	*line;

	//antes de acabar, dejar en (s) el texto sobrante tras el '\n'
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_save_buffers(fd, s);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	if (!line)
		return (NULL);
	return (s);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
