/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:02:39 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 02:08:24 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_char(char character, char const *set)
{
	while (*set)
		if (*set++ == character)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	start_str;
	size_t	end_str;

	if (!s1)
		return (NULL);
	start_str = 0;
	while (s1[start_str] && find_char(s1[start_str], set))
		start_str++;
	end_str = ft_strlen(s1);
	while (start_str != end_str && find_char(s1[end_str - 1], set))
		end_str--;
	strtrim = ft_substr(s1, start_str, end_str - start_str);
	return (strtrim);
}
