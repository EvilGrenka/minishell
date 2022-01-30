/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:48:17 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 23:22:55 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int check)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (check & 1)
		free((char *)s1);
	if (check & 2)
		free((char *)s2);
	return (result);
}