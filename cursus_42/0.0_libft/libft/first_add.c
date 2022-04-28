/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/04/28 11:32:42 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i - 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	char s[] = "hola soy manolo";

	printf("%s", ft_substr(s, 5, 7));
}
