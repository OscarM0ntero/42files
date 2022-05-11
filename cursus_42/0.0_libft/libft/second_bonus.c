/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:26:06 by omontero          #+#    #+#             */
/*   Updated: 2022/05/10 11:01:54 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	while (lst)
	{
		tmp = lst->next;
		f(tmp);
		lst = tmp;
	}
}

/*
Itera la lista lst y aplica f al content de cada
nodo. Crea la lista resultante de aplicar f a cada
nodo y la devuelve. del se usa para eliminar
contenido de un nodo si fuera necesario.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			while (list)
			{
				tmp = list->next;
				(*del)(list->content);
				free(list);
				list = tmp;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&list, tmp);
		lst = lst->next;
	}
	return (list);
}
