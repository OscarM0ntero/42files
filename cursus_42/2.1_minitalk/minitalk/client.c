/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2023/01/11 15:57:39 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit_error(void)
{
	write(1, "Error. Debe introducir: $ ./client (PID_NUMBER) (string) \n.", 58);
	exit(EXIT_FAILURE);
}

void	handler(int signal)
{
	static int	bytes_received = 0;
	char		*c;

	if (signal == SIGUSR2)
		bytes_received++;
	else
	{
		c = ft_itoa(bytes_received);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

void	send_msg(pid_t pid, char *msg)
{
	int		i;
	int		j;

	i = -1;
	while (msg[++i])
	{
		j = 8;
		while (j--)
		{
			if (msg[i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = -1;
	while (i++ <= 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	size_t	msg_len;
	char	*c;

	if (argc != 3)
		ft_exit_error();
	msg_len = ft_strlen(argv[2]);
	if (!msg_len || !ft_atoi(argv[1]))
		ft_exit_error();
	write(1, "Bytes sent        : ", 20);
	c = ft_itoa(msg_len);
	write(1, c, ft_strlen(c));
	free (c);
	write(1, "\nBytes received    : ", 21);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_msg(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
