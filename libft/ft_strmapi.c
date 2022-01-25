/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:32:03 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:27:30 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*change_s;
	size_t	i;

	if (!s || !f)
		return (NULL);
	change_s = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!change_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		change_s[i] = (*f)(i, s[i]);
		i++;
	}
	change_s[i] = '\0';
	return (change_s);
}
