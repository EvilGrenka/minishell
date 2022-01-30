/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:47:17 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 20:07:36 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

#include <stdlib.h>

typedef struct s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*prev;
	void			*content;
}				t_dlist;

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_list);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new_list);
void	ft_dlstclear(t_dlist **lst, void (*del)(void*));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void*));
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstnew(void	*content);
int		ft_dsize(t_dlist *lst);

#endif