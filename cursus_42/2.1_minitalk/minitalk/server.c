/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2023/01/10 13:05:14 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	var_initialize(t_message *var)
{
	var->char_val = 0;
	var->bit_pos = 0;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static t_message	message;

	(void)context;
	if (message.pid != info->si_pid)
		var_initialize(&message);
	if (info->si_pid)
		message.pid = info->si_pid;
	(message.char_val) = (message.char_val) | (sig == SIGUSR1);
	if (++(message.bit_pos) == 8)
	{
		if (!(message.char_val))
		{
			kill(message.pid, SIGUSR1);
			return ;
		}
		ft_putchar_fd((message.char_val), 1);
		kill(message.pid, SIGUSR2);
		var_initialize(&message);
	}
	else
		(message.char_val) = (message.char_val) << 1;
}

int	main(void)
{
	struct sigaction	sigact;
	pid_t				pid_sv;

	pid_sv = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid_sv, 1);
	write(1, "\n", 1);
	sigact.sa_sigaction = action;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
