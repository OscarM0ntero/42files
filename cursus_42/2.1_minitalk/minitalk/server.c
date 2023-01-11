/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2023/01/11 14:47:37 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	var_initialvar_initize(t_message *var)
{
	var->c_val = 0;
	var->b_pos = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static t_message	message;

	(void)context;
	if (message.pid != info->si_pid)
		var_init(&message);
	if (info->si_pid)
		message.pid = info->si_pid;
	(message.c_val) = (message.c_val) | (sig == SIGUSR1);
	if (++(message.b_pos) == 8)
	{
		if (!(message.c_val))
		{
			kill(message.pid, SIGUSR1);
			return ;
		}
		write(1, &message.c_val, 1);
		kill(message.pid, SIGUSR2);
		var_init(&message);
	}
	else
		(message.c_val) = (message.c_val) << 1;
}

int	main(void)
{
	struct sigaction	sigact;
	pid_t				pid_sv;
	char				*c;

	pid_sv = getpid();
	c = ft_itoa(pid_sv);
	write(1, "PID: ", 5);
	write(1, c, ft_strlen(c));
	free (c);
	write(1, "\n", 1);
	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
