/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:47:19 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:00:33 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = ft_strlen(destination);
	i = len_dst;
	j = 0;
	if (dstsize > 0 && len_dst < dstsize - 1)
	{
		while (source[j] && len_dst + j < dstsize - 1)
			destination[i++] = source[j++];
		destination[i] = '\0';
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (ft_strlen(source) + len_dst);
}
