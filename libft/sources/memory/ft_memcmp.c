/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:45:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:05:39 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*local_s1;
	const unsigned char	*local_s2;

	local_s1 = s1;
	local_s2 = s2;
	if (!n)
		return (0);
	while (*local_s1 == *local_s2 && --n)
	{
		local_s1++;
		local_s2++;
	}
	return (*local_s1 - *local_s2);
}
