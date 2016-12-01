/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:51:31 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/30 20:02:44 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_checkthepiece(t_tablist *lst, int i, int j, int k)
{
	(lst->tab)[i][j] = lst->letter;
	if ((lst->tab)[i][j + 1] == '#')
		k = ft_checkthepiece(lst, i, j + 1, k + 1);
	if ((lst->tab)[i + 1][j] == '#')
		k = ft_checkthepiece(lst, i + 1, j, k + 1);
	if ((lst->tab)[i][j - 1] == '#')
		k = ft_checkthepiece(lst, i, j - 1, k + 1);
	return (k);
}

void	ft_ij_min(char **piece, int *i_min, int *j_min, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == letter && i < *i_min)
				*i_min = i;
			if (piece[i][j] == letter && j < *j_min)
				*j_min = j;
			j++;
		}
		i++;
	}
}

void	ft_place_up_left(char **piece, int i_min, int j_min, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == letter)
			{
				piece[i][j] = '.';
				piece[i - i_min][j - j_min] = letter;
			}
			j++;
		}
		i++;
	}
}

int		ft_checkpieces(t_tablist *list, int *nbr_pieces)
{
	int		k;
	char	letter;
	int		i_min;
	int		j_min;

	letter = 'A';
	while (list != NULL)
	{
		list->letter = letter;
		if ((k = ft_checkthepiece(list, list->i, list->j, 0)) != 3)
			return (0);
		i_min = 4;
		j_min = 4;
		ft_ij_min(list->tab, &i_min, &j_min, letter);
		ft_place_up_left(list->tab, i_min, j_min, letter);
		letter++;
		list = list->next;
	}
	*nbr_pieces = letter - 'A';
	while (list != NULL)
	{
		list->size = *nbr_pieces;
		list = list->next;
	}
	return (1);
}
