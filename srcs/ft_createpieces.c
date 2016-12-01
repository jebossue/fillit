/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createpieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:33:58 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/29 16:12:57 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		ft_lstpushback(t_tablist *begin, t_tablist *list)
{
	while (begin->next != NULL)
		begin = begin->next;
	begin->next = list;
}

void		ft_setotherarg(t_tablist *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (list->tab[i][j] != '#' && list->tab[i][j] != '\n')
			j++;
		if (list->tab[i][j] == '#')
		{
			list->i = i;
			list->j = j;
			return ;
		}
		i++;
	}
	list->size = 0;
}

t_tablist	*ft_tablstnew(char *content, size_t content_size)
{
	t_tablist	*list;
	int			i;
	int			j;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	if (content == NULL)
		list->tab = NULL;
	else
	{
		if ((list->tab = malloc(sizeof(char*) * ((content_size) + 1))) == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (i < 5)
		{
			list->tab[i] = ft_strsub(content, j, 5);
			j += 5;
			i++;
		}
		list->tab[i] = NULL;
		ft_setotherarg(list);
	}
	list->next = NULL;
	return (list);
}
