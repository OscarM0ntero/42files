/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixth_libc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:25:56 by oscar             #+#    #+#             */
/*   Updated: 2022/05/18 16:13:22 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1) + 1;
	p = (char *)malloc(len * sizeof(char));
	if (!p)
		return (NULL);
	p = ft_memcpy(p, s1, len);
	return (p);
}
