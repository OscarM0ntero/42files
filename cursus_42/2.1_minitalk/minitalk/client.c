/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:48 by omontero          #+#    #+#             */
/*   Updated: 2022/10/19 17:01:35 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit_error(void)
{
	ft_putstr_fd("Wrong Input.\n", STDOUT_FILENO);
	ft_putstr_fd("Must be: $ ./client (PID_NUMBER) (string) \n.", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	action(int signal)
{
	static int	bytes_received = 0;

	if (signal == SIGUSR2)
		bytes_received++;
	else
	{
		ft_putnbr_fd(bytes_received, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	send_signal(pid_t pid, char *str)
{
	int		i;
	int		j;

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

int	main(int argc, char **argv)
{
	size_t	str_len;

	if (argc != 3)
		ft_exit_error();
	str_len = ft_strlen(argv[2]);
	if (!str_len || !ft_atoi(argv[1]))
		ft_exit_error();
	ft_putstr_fd("Bytes sent        : ", STDOUT_FILENO);
	ft_putnbr_fd(str_len, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd("Bytes received    : ", STDOUT_FILENO);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
