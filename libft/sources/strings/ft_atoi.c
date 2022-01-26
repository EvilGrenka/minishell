/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:15:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 04:21:06 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char c)
{
	return (c == '\f' || c == '\r' || c == ' '
		|| c == '\t' || c == '\n' || c == '\v');
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	int					rank;

	sign = 1;
	rank = 0;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str++ - '0');
		rank++;
	}
	if (rank > 19 || result > 9223372036854775807L)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)(result * sign));
}
