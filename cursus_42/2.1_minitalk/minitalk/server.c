/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2023/01/16 12:35:13 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_status = 1;

void	showleaks(void)
{
	system("leaks -q server");
}

//	Reorganiza como se administran las señales SIGUSR1 y SIGUSR2
void	handler(int sig, siginfo_t *info, void *context)
{
	static t_message	msg;

	(void)context;
	if (msg.pid != info->si_pid)
	{
		msg.c_val = 0;
		msg.b_pos = 0;
	}
	if (info->si_pid)
		msg.pid = info->si_pid;
	(msg.c_val) = (msg.c_val) | (sig == SIGUSR1);
	if (++(msg.b_pos) == 8)
	{
		if (!(msg.c_val))
		{
			kill(msg.pid, SIGUSR2);
			return ;
		}
		write(1, &msg.c_val, 1);
		kill(msg.pid, SIGUSR1);
		msg.c_val = 0;
		msg.b_pos = 0;
	}
	else
		(msg.c_val) = (msg.c_val) << 1;
}

//	Apaga el servidor, pasando el g_status a 0
void	turn_off(int sig)
{
	(void)sig;
	write(1, "\nServer closed.\n", 16);
	g_status = 0;
}

//	Imprime el PID
void	print_pid(pid_t pid)
{
	char	*c;

	c = ft_itoa(pid);
	write(1, "PID: ", 5);
	write(1, c, ft_strlen(c));
	free (c);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	pid_t				pid_sv;

	argv = NULL;
	(void)argv;
	if (argc != 1)
		return (write(2, "Only <./server>, no arguments needed.\n", 38), 1);
	pid_sv = getpid();
	print_pid(pid_sv);
	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	signal(SIGINT, &turn_off);
	write(1, "\n", 1);
	while (g_status)
	{
	}
	return (0);
}
