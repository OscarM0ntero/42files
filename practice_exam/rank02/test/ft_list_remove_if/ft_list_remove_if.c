#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !*begin_list)
		return ;
	
	t_list	*list = *begin_list;

	if (!cmp(list->data, data_ref))
	{
		*begin_list = list->next;
		free(list);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	list = *begin_list;
	ft_list_remove_if(&list->next, data_ref, cmp);
}
