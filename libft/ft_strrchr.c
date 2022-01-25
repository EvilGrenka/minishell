/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:51:47 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 16:57:13 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*local_s;

	local_s = s;
	while (*local_s)
		local_s++;
	if (c == '\0')
		return ((char *)local_s);
	while (--local_s >= s)
		if ((char)c == *local_s)
			return ((char *)local_s);
	return (NULL);
}
