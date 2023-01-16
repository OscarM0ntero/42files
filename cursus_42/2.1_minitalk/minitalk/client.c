/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2023/01/16 13:12:12 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit_error(void)
{
	write(2, "Error. Debe introducir: ./client (PID) (string).\n", 51);
	exit(EXIT_FAILURE);
}

//	Reorganiza como se administran las señales SIGUSR1 y SIGUSR2
//	SIGUSR1 -> Suma 1 al contados de Bytes recibidos
//	SIGUSR2 -> Imprime la confirmacion de los Bytes recibidos
void	handler(int signal)
{
	static int	bytes_received = 0;
	char		*c;

	if (signal == SIGUSR1)
		bytes_received++;
	else
	{
		c = ft_itoa(bytes_received);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

/*	Envia todo el mensaje, una vez enviado envia 8 bits vacios,
	para que el servidor nos responda con la comprobacion de que
	ha recibido todos los Bytes correctamente */
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
			usleep(50);
		}
	}
	i = -1;
	while (i++ < 7)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	size_t	msg_len;
	pid_t	pid;
	char	*c;

	if (argc != 3)
		ft_exit_error();
	msg_len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	if (!msg_len || !pid)
		ft_exit_error();
	write(1, "Bytes enviados        : ", 24);
	c = ft_itoa(msg_len);
	write(1, c, ft_strlen(c));
	free (c);
	write(1, "\nBytes recibidos       : ", 25);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_msg(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
