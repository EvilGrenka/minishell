/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:39 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/26 15:06:48 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list *lst)
{
	int		i;
	t_list	*tmp;
	void	**result;

	result = malloc(sizeof(void *) * (ft_lstsize(lst) + 1));
	if (result == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		result[i++] = (lst)->content;
		tmp = lst;
		lst = lst->next;
		free(lst);
	}
	result[i] = 0;
	return (result);
}