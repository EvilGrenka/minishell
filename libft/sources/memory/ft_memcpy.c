/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:37:58 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:50:13 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	const unsigned char	*local_src;
	unsigned char		*local_dest;

	if (!destination && !source)
		return (NULL);
	local_src = source;
	local_dest = destination;
	while (n--)
		*local_dest++ = *local_src++;
	return (destination);
}
