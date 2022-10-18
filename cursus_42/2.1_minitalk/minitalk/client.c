/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/18 21:14:57 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit_error(void)
{
	ft_putstr_fd("Usage case: \"./client SERVER_PID MESSAGE\" \n.", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	action(int signal)
{
	static int	bytes_recieved;

	bytes_recieved = 0;
	if (signal == SIGUSR2)
	{
		bytes_recieved++;
	}
	else
	{
		ft_putnbr_fd(bytes_recieved, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	send_signal(pid_t pid, char *str)
{
	int	i;
	int	j;

	j = -1;
	while (str[++j])
	{
		i = 8;
		while (i--)
		{
			if (str[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv[])
{
	int	str_len;

	if (argc != 3)
		ft_exit_error();
	str_len = ft_strlen(argv[2]);
	if (!str_len || !ft_atoi(argv[1]))
		ft_exit_error();
	ft_putstr_fd("Bytes sent		: ", STDOUT_FILENO);
	ft_putnbr_fd(str_len, STDIN_FILENO);
	ft_putchar_fd('\n', stdout);
	ft_putstr_fd("Bytes received	: ", STDOUT_FILENO);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
