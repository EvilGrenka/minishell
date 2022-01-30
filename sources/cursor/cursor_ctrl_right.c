/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_ctrl_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:30:29 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 19:30:40 by rnoriko          ###   ########.fr       */
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