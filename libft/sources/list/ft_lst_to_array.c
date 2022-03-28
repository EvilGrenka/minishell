/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:25:22 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:25:22 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list *lst)
{
	int		i;
	void	**result;

	result = malloc(sizeof(void *) * (ft_lstsize(lst) + 1));
	if (result == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		result[i++] = (lst)->content;
		lst = lst->next;
		free(lst);
	}
	result[i] = 0;
	return (result);
}
