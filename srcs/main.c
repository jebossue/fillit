/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:22:20 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/30 19:36:57 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_tablstdel(t_tablist **tablst)
{
	if (!tablst || !(*tablst))
		return ;
	ft_tablstdel(&((*tablst)->next));
	free(tablst);
}

void	ft_print(int size, char **result)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(result[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_tablist	*list;
	int			nbr_pieces;
	char		**result;

	if (argc < 2)
	{
		ft_putstr("Too few parameters !\n");
		return (0);
	}
	if ((list = ft_open(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	nbr_pieces = 0;
	if (ft_checkpieces(list, &nbr_pieces) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	result = ft_result(list, nbr_pieces);
	ft_print(list->size, result);
	return (0);
}
