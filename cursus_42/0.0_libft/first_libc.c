/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_libc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:58:48 by omontero          #+#    #+#             */
/*   Updated: 2022/04/21 18:49:07 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (n);
	return (0);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (n);
	return (0);
}

int	ft_isalnum(int n)
{
	if (ft_isalpha || ft_isdigit)
		return (1);
	return (0);
}

int	ft_isascii(int n)
{
	if (n >= 0 && n <= 127)
		return (n);
	return (0);
}

int	ft_isprintf(int n)
{
	if (n >= 32 && n <= 126)
		return (1);
	return (0);
}
