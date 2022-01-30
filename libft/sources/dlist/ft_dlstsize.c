/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:14:34 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 20:15:31 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_d_size(t_dlist *lst)
{
	int	dsizelist;

	dsizelist = 0;
	while (lst)
	{
		lst = lst->next;
		++dsizelist;
	}
	return (dsizelist);
}