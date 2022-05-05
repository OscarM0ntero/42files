/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:26:06 by omontero          #+#    #+#             */
/*   Updated: 2022/05/05 08:59:50 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	new_nodo;

	new_nodo.content = (void *)malloc(ft_strlen((char *)content)
			* sizeof(char));
	new_nodo.content = content;
	new_nodo.next = (void *)malloc(1 * sizeof(t_list));
	new_nodo.next = NULL;
	return (&new_nodo);
}
