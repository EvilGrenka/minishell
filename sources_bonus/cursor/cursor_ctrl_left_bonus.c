/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_ctrl_left_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:09:14 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:09:14 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
