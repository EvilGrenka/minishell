/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:09:44 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:09:45 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	delete_line(void)
{
	tputs(tgetstr("dl", NULL), 1, putchar_tc);
	tputs(tgetstr("cr", NULL), 1, putchar_tc);
}
