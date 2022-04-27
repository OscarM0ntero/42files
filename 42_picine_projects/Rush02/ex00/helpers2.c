/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmgarc <carmgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:10:42 by carmgarc          #+#    #+#             */
/*   Updated: 2022/04/03 20:10:45 by carmgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_number(int j)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc((j - 1) * 3 + 2);
	free(str);
	str[0] = '1';
	while (i < (j - 1) * 3 + 1)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	return (str);
}

void	print_between(int actual_box, char *dic)
{
	write(1, " ", 1);
	if (actual_box > 1)
		putstr(number_to_word(get_number(actual_box), dic));
}
