/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:28:13 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/30 20:05:42 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_delpiece(char **result, char letter, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (result[x][y] == letter)
				result[x][y] = '.';
			y++;
		}
		x++;
	}
}

int		ft_placepiece(t_tablist *list, char **result, int i, int j)
{
	int	x;
	int	y;
	int	nbr_pieces;

	x = -1;
	nbr_pieces = 0;
	while (x++ < 4)
	{
		y = -1;
		while (y++ < 4)
		{
			if (i + x < list->size && j + y < list->size &&
				result[i + x][j + y] == '.' && list->tab[x][y] == list->letter)
			{
				result[i + x][j + y] = list->letter;
				nbr_pieces++;
			}
		}
	}
	if (nbr_pieces != 4)
	{
		ft_delpiece(result, list->letter, list->size);
		return (0);
	}
	return (1);
}

void	ft_sizeplusplus(t_tablist *lst, int size)
{
	while (lst != NULL)
	{
		lst->size = size + 1;
		lst = lst->next;
	}
}

int		ft_firstarray(t_tablist *list, char **result, int i, int j)
{
	if (list == NULL)
		return (1);
	while (i < list->size)
	{
		j = 0;
		while (j < list->size)
		{
			if ((ft_placepiece(list, result, i, j)) == 1)
			{
				if ((ft_firstarray(list->next, result, 0, 0)) == 1)
					return (1);
				j--;
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_result(t_tablist *list, int nbr_pieces)
{
	char	**result;

	result = ft_set_custom_tab(nbr_pieces * 4, nbr_pieces * 4, '.');
	ft_sizeplusplus(list, (nbr_pieces / 2) - 1);
	while ((ft_firstarray(list, result, 0, 0)) == 0)
		ft_sizeplusplus(list, list->size);
	return (result);
}
