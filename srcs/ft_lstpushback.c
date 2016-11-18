#include "libft.h"

t_tablist	ft_lstpushback(t_tablist **begin, t_tablist *list)
{
	while (begin->next != NULL)
		begin = begin->next;
		begin->next = list;
}
