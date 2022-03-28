/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:39:41 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 11:53:23 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_line(void)
{
	tputs(tgetstr("dl", NULL), 1, putchar_tc);
	tputs(tgetstr("cr", NULL), 1, putchar_tc);
}
