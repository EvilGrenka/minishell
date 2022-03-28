/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_ctrl_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:38:54 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:38:54 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cursor_ctrl_left(void)
{
	while (g_sh.cmd_i > 0 && g_sh.line[g_sh.cmd_i - 1] == ' ')
	{
		cursor_left();
		--g_sh.cmd_i;
	}
	while (g_sh.cmd_i > 0 && g_sh.line[g_sh.cmd_i - 1] != ' ')
	{
		cursor_left();
		--g_sh.cmd_i;
	}
}
