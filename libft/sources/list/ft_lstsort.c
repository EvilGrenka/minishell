/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:27:27 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:27:28 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*compare)(t_list *a, t_list *b))
{
	t_list	**bubble_a;
	t_list	**bubble_b;
	void	*tmp;

	bubble_a = lst;
	while ((*bubble_a)->next)
	{
		bubble_b = &(*bubble_a)->next;
		while ((*bubble_b))
		{
			if ((*compare)(*bubble_a, *bubble_b))
			{
				tmp = (*bubble_a)->content;
				(*bubble_a)->content = (*bubble_b)->content;
				(*bubble_b)->content = tmp;
			}
			bubble_b = &(*bubble_b)->next;
		}
		bubble_a = &(*bubble_a)->next;
	}
}
