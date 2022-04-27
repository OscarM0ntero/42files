/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:50:52 by omontero          #+#    #+#             */
/*   Updated: 2022/04/02 16:48:37 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z') && !(str[i
						- 1] >= 'A' && str[i - 1] <= 'Z') && !(str[i
						- 1] >= '0' && str[i - 1] <= '9'))
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if ((str[i - 1] >= 'a' && str[i - 1] <= 'z') || (str[i
						- 1] >= 'A' && str[i - 1] <= 'Z') || (str[i
						- 1] >= '0' && str[i - 1] <= '9'))
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
