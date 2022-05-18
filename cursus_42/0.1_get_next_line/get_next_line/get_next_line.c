/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:32 by omontero          #+#    #+#             */
/*   Updated: 2022/05/18 19:09:00 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save_buffers(int fd, char *s)
{
	char	*tmp_buff;
	int		read_output;

	tmp_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buff)
		return (NULL);
	read_output = 1;
	while (!ft_strchr(tmp_buff, '\n') && read_output != 0)
	{
		read_output = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_output == -1)
		{
			free(tmp_buff);
			return (NULL);
		}
		tmp_buff[read_output] = '\0';
		s = ft_strjoin(s, tmp_buff);
	}
	free(tmp_buff);
	return (s);
}

static char	*ft_line(char *s)
{
	char	*line;
	int		i;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_last_buff(char *s)
{
	int		i;
	int		j;
	char	*extra;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	extra = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		extra[j++] = s[i++];
	extra[j] = '\0';
	free(s);
	return (extra);
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
	line = ft_line(s);
	if (!line)
		return (NULL);
	s = ft_last_buff(s);
	if (!s)
		return (NULL);
	return (line);
}

/* int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}  */
