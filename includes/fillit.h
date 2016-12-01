/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:16:56 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/30 19:36:23 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tablist
{
	char				**tab;
	int					i;
	int					j;
	int					i_max;
	int					j_max;
	char				letter;
	int					size;
	struct s_tablist	*next;
}				t_tablist;

t_tablist		*ft_tablstnew(char *content, size_t content_size);
void			ft_lstpushback(t_tablist *begin, t_tablist *list);
t_tablist		*ft_open(char *file);
int				ft_checkpieces(t_tablist *list, int *nbr_pieces);
void			ft_tablstdel(t_tablist **tablst);
char			**ft_result(t_tablist *list, int nbr_pieces);
void			ft_print(int size, char **result);

#endif
