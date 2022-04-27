/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:56:32 by omontero          #+#    #+#             */
/*   Updated: 2022/04/06 10:24:46 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

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

void	print_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	*c;

	a = 1;
	while (a < argc)
	{
		b = 1;
		while (b < argc)
		{
			if (ft_strcmp(argv[a], argv[b]) < 0)
			{
				c = argv[a];
				argv[a] = argv[b];
				argv[b] = c;
			}
			b++;
		}
		a++;
	}
	print_args(argc, argv);
	return (0);
}
