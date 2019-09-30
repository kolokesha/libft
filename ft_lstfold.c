#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(*f)(void *, void *))
{
	t_list *list;
	void	*res;

	list = lst;
	res = list->content;
	list = list->next;
	while (list)
	{
		res = f(res, list->content);
		list = list->next;
	}
	return (res);
}
