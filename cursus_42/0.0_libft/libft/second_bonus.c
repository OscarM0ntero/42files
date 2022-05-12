/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:26:06 by omontero          #+#    #+#             */
/*   Updated: 2022/05/12 19:01:47 by omontero         ###   ########.fr       */
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
	f(lst->content);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		f(tmp->content);
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
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	list = ft_lstnew(lst->content);
	while (tmp->next != NULL)
	{
		new = ft_lstnew((*f)(tmp->content));
		if (!new)
			return (NULL);
		ft_lstadd_back(list, new);
		(*del)(new->content);
		free(new);
		tmp = tmp->next;
	}
	return (list);
}

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			while (new)
			{
				tmp = new->next;
				(*del)(new->content);
				free(new);
				new = tmp;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (list);
} */
