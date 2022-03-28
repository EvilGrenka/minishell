/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:24:46 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:24:47 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_d_list	*ft_d_lstlast(t_d_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}