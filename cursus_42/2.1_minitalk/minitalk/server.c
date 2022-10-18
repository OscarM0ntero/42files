/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/18 21:40:52 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	var_init(t_message *var)
{
	var->char_val = 0;
	var->bit_pos = 0;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static t_message	message;

	(void)context;
	if (message.pid != info->si_pid)
		var_init(&message);
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
		kill(message.pid, SIGUSR1);
		var_init(&message);
	}
	else
		(message.char_val) = (message.char_val) << 1;
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid_server;

	pid_server = getpid();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid_server, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
