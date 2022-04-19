/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:09:14 by omontero          #+#    #+#             */
/*   Updated: 2022/04/02 13:09:14 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	x;

	x = 1;
	i = 0;
	while (str[i] != '\0' && x != 0)
	{
		if ((str[i] < 'A' || str[i] > 'Z'))
		{
			x = 0;
		}
		i++;
	}
	return (x);
}
