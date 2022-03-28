/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:26:39 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:27:18 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*curr;

	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (0);
	curr = result;
	lst = lst->next;
	while (lst)
	{
		curr->next = ft_lstnew(f(lst->content));
		if (curr->next == NULL)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (result);
}
