/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:28:39 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:28:40 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc(void **dst, size_t size)
{
	*dst = ft_calloc(size, 1);
	if (*dst == NULL)
		return (0);
	return (1);
}
