#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (lst || del)
	{	
		while (*lst)
		{
			current = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = current;
		}
	}
}
