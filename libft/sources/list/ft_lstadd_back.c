/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:15:23 by rnoriko           #+#    #+#             */
/*   Updated: 2021/04/30 16:00:41 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev_last;

	if (lst && *lst)
	{
		prev_last = *lst;
		while (prev_last->next)
			prev_last = prev_last->next;
		prev_last->next = new;
	}
	else if (lst)
		*lst = new;
}
