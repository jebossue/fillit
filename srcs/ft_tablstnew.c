#include "libft.h"

t_tablist	*ft_tablstnew(char *content, size_t content_size)
{
	t_tablist	*list;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->tab = NULL;
	}
	else
	{
		if ((list->tab = malloc(content_size) + 1) == NULL)
			return (NULL);
		while (*content && content)
		{
			ft_strsub(content, 0, );
			content += 5;
		}
	}
	list->next = NULL;
	return (list);
}
