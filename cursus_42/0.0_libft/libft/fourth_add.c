/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:17:37 by omontero          #+#    #+#             */
/*   Updated: 2022/05/03 12:08:51 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	p = ft_strdup(s);
	if (!p)
		return (p = NULL);
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	while (s[i])
	{
		p = &s[i];
		s[i] = (char)((*f)(i, p));
		i++;
	}
	return (s);
}
// fix type conversion