/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmgarc <carmgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:12:22 by carmgarc          #+#    #+#             */
/*   Updated: 2022/04/03 20:10:15 by carmgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*concat_numbers(char s1, char s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 3);
	free(str);
	str[0] = s1;
	str[1] = s2;
	str[2] = 0;
	return (str);
}

char	*contact_number_alone(char s1)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	free(str);
	str[0] = s1;
	str[1] = 0;
	return (str);
}

void	print_box_of_2_elements(char *str, char *dic)
{
	if (str[0] == '1')
		putstr(number_to_word(concat_numbers(str[0], str[1]), dic));
	else
	{
		putstr(number_to_word(concat_numbers(str[0], '0'), dic));
		if (str[1] != '0')
		{
			write(1, "-", 1);
			putstr(number_to_word(contact_number_alone(str[1]), dic));
		}
	}
}

void	print_box_of_3_elements(char *str, char *dic)
{
	if (str[0] != '0')
	{
		putstr(number_to_word(contact_number_alone(str[0]), dic));
		write(1, " ", 1);
		putstr(number_to_word("100", dic));
		if (str[1] != '0' || str[2] != '0')
			write(1, " ", 1);
	}
	if (str[1] != '0' || str[2] != '0')
	{
		if (str[1] == '0')
			putstr(number_to_word(&str[2], dic));
		else if (str[1] == '1')
			putstr(number_to_word(concat_numbers(str[1], str[2]), dic));
		else
		{
			putstr(number_to_word(concat_numbers(str[1], '0'), dic));
			if (str[2] != '0')
			{
				write(1, "-", 1);
				putstr(number_to_word(contact_number_alone(str[2]), dic));
			}
		}
	}
}

void	print_number(char *str, char *dic)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (len == 1)
		putstr(number_to_word(str, dic));
	else if (len == 2)
		print_box_of_2_elements(str, dic);
	else
		print_box_of_3_elements(str, dic);
}
