/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:05:55 by omontero          #+#    #+#             */
/*   Updated: 2022/04/02 13:06:24 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
}
