/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:04:58 by omontero          #+#    #+#             */
/*   Updated: 2022/04/06 12:07:44 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (!(argc > 0))
		return (-1);
	ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);
}
