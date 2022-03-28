/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_ctrl_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:39:13 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:39:14 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cursor_ctrl_right(void)
{
	while (g_sh.cmd_i < g_sh.cmd_s && g_sh.line[g_sh.cmd_i] == ' ')
	{
		cursor_right();
		++g_sh.cmd_i;
	}
	while (g_sh.cmd_i < g_sh.cmd_s && g_sh.line[g_sh.cmd_i] != ' ')
	{
		cursor_right();
		++g_sh.cmd_i;
	}
}
