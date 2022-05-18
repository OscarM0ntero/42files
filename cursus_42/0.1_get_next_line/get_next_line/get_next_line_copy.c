/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/05/18 16:56:29 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "get_next_line.h"

static char	*ft_read(int fd, char *buffer)
{
	char	*temp_buff;
	int		read_bytes;

	temp_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, temp_buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp_buff);
			return (NULL);
		}
		temp_buff[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, temp_buff);
	}
	free(temp_buff);
	return (buffer);
}

static char	*ft_buff(char *buffer)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (buffer[i])
		s[c++] = buffer[i++];
	s[c] = '\0';
	free(buffer);
	return (s);
}

static char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_buff(buffer);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
 */