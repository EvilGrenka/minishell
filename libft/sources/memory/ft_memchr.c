/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:29:09 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:00:57 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*local_s;

	local_s = (unsigned char *)s;
	while (n--)
	{
		if (*local_s == (unsigned char)(c))
			return (local_s);
		local_s++;
	}
	return (NULL);
}
