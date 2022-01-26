/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:45:19 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 05:14:35 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*local_src;
	unsigned char		*local_dst;

	local_src = src;
	local_dst = dst;
	if (local_src == local_dst || len == 0)
		return (dst);
	if (local_dst < local_src)
		while (len--)
			*local_dst++ = *local_src++;
	else
	{
		local_dst += len;
		local_src += len;
		while (len--)
			*--local_dst = *--local_src;
	}
	return (dst);
}
