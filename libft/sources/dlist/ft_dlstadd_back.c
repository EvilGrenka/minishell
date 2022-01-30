/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:57:47 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 20:11:54 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_list)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	last = ft_dlstlast(*lst);
	last->next = new_list;
	new_list->prev = last;
}