/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:24:27 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:24:27 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstadd_front(t_d_list **lst, t_d_list *new_list)
{
	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	new_list->next = *lst;
	(*lst)->prev = new_list;
	*lst = new_list;
}
