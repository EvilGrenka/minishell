/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappendc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:51:45 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 22:51:56 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappendc(char *str, char c)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	if (!ft_malloc((void **)&result, sizeof(char *) * (len + 2)))
	{
		free(str);
		return (0);
	}
	ft_memmove(result, str, sizeof(char) * len);
	result[len] = c;
	free(str);
	return (result);
}