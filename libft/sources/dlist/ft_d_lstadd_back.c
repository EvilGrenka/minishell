/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:24:19 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:24:21 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstadd_back(t_d_list **lst, t_d_list *new_list)
{
	t_d_list	*last;

	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	last = ft_d_lstlast(*lst);
	last->next = new_list;
	new_list->prev = last;
}
