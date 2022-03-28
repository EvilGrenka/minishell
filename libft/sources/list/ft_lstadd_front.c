/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:25:41 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:25:41 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_front - Adds the element 'new' at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new_list)
{
	new_list->next = *lst;
	*lst = new_list;
}
