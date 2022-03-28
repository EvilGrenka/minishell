/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_ctrl_right_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:09:19 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:09:20 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
