/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:22:41 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/19 23:29:57 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strdup;
	size_t	i;

	strdup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (strdup)
	{
		i = 0;
		while (s1[i])
		{
			strdup[i] = s1[i];
			i++;
		}
		strdup[i] = '\0';
	}
	return (strdup);
}
