/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:22:23 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/30 19:35:20 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		ft_buffisgood(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] && i < 21)
	{
		if (str[i] == '#')
			k++;
		if ((k > 4 || (i == 4 || i == 9 || i == 14 || i == 19 || i == 20))
				&& str[i] != '\n')
			return (0);
		else if ((k > 4 || (i != 4 && i != 9 && i != 14 && i != 19 && i != 20))
				&& (str[i] != '.' && str[i] != '#'))
			return (0);
		i++;
	}
	if (k != 4)
		return (0);
	return (1);
}

static int		ft_checklastpiece(t_tablist *list)
{
	while (list->next)
		list = list->next;
	if (list->tab[4][0] != '\0')
		return (0);
	return (1);
}

t_tablist		*ft_open(char *file)
{
	t_tablist	*begin_list;
	int			fd;
	int			ret;
	char		buff[21];

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	begin_list = NULL;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (!(ft_buffisgood(buff)) || ret < 20)
			return (NULL);
		if (begin_list == NULL)
			begin_list = ft_tablstnew(buff, 5);
		else
			ft_lstpushback(begin_list, ft_tablstnew(buff, 5));
	}
	if ((begin_list == NULL || ft_checklastpiece(begin_list)) == 0)
		return (NULL);
	return (begin_list);
}
