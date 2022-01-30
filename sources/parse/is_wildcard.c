/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:42:07 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/29 14:42:20 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_wildcard(char *str)
{
	int		flag;

	flag = TK_NONE;
	while (*str)
	{
		if (flag == TK_NONE && *str == '*')
			return (1);
		if (!(flag & ~(TK_QOUTES)) && *str == '"')
			flag ^= TK_QOUTES;
		else if (!(flag & ~(TK_QOUTE)) && *str == '\'')
			flag ^= TK_QOUTE;
		else if (!(flag & ~(TK_QOUTES)) && *str == '\\')
			flag |= TK_ESCAPE;
		else if ((flag & TK_ESCAPE) && *(str - 1) == '\\')
			flag &= ~TK_ESCAPE;
		++str;
	}
	return (0);
}