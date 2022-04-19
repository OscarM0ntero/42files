/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antrujil <antrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:36:14 by antrujil          #+#    #+#             */
/*   Updated: 2022/04/02 13:05:56 by antrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive(int index)
{
	if (index == 0)
	{
		return (0);
	}
	else if (index == 1)
	{
		return (1);
	}
	else
	{
		return (recursive(index - 1) + recursive(index - 2));
	}
}

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	else
	{
		return (recursive(index));
	}
}
