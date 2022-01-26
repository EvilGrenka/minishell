/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:22:28 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:04:40 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	const unsigned char	*local_source;
	unsigned char		*local_destination;

	local_source = source;
	local_destination = destination;
	while (n--)
	{
		*local_destination = *local_source;
		if (*local_source == (unsigned char)c)
			return (++local_destination);
		++local_source;
		++local_destination;
	}
	return (NULL);
}
