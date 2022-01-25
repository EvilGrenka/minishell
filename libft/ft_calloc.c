/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:11:32 by rnoriko           #+#    #+#             */
/*   Updated: 2021/11/04 15:24:09 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem_alloc;
	size_t	lsize;

	lsize = size * count;
	if (count && size != (lsize / count))
		return (NULL);
	mem_alloc = malloc(size * count);
	if (!mem_alloc)
		return (NULL);
	ft_memset(mem_alloc, 0, size * count);
	return (mem_alloc);
}
