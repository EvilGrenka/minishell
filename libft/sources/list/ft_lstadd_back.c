/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:25:31 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:25:32 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_back - Adds the element 'new' at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	if (*lst == 0)
		*lst = new_list;
	else
		(ft_lstlast(*lst))->next = new_list;
}
