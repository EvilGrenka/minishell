/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:22:39 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 11:18:30 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_key_delete(char *line)
{
	char	*new_line;
	char	*new_line_front;

	new_line_front = ft_strndup(line, g_sh.cmd_i - 1);
	if (new_line_front == NULL)
		return (0);
	if (g_sh.cmd_i != g_sh.cmd_s)
		new_line = ft_strjoin_free(new_line_front, line + g_sh.cmd_i, 1);
	else
		new_line = new_line_front;
	--g_sh.cmd_i;
	--g_sh.cmd_s;
	cursor_left();
	delete_char();
	ft_free(line);
	return (new_line);
}

static void	handle_key_move(int keycode)
{
	if (g_sh.cmd_i > 0 && keycode == ARROW_LEFT)
	{
		cursor_left();
		--g_sh.cmd_i;
	}
	else if (g_sh.cmd_i < g_sh.cmd_s && keycode == ARROW_RIGHT)
	{
		cursor_right();
		++g_sh.cmd_i;
	}
	else if (keycode == CTRL_LEFT)
		cursor_ctrl_left();
	else if (keycode == CTRL_RIGHT)
		cursor_ctrl_right();
}

static void	handle_home_end(int keycode)
{
	if (keycode == KEY_HOME)
	{
		while (g_sh.cmd_i > 0)
		{
			cursor_left();
			--g_sh.cmd_i;
		}
	}
	else if (keycode == KEY_END)
	{
		while (g_sh.cmd_i < g_sh.cmd_s)
		{
			cursor_right();
			++g_sh.cmd_i;
		}
	}
}

void	handle_key_input(int keycode)
{
	if (g_sh.cmd && is_arrow_up_down(keycode))
		return (handle_history(keycode));
	if (is_delete(keycode) && g_sh.cmd_i > 0)
	{
		g_sh.line = handle_key_delete(g_sh.line);
		if (g_sh.line == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit_minishell(1);
		}
		return ;
	}
	if (is_arrow_left_right(keycode))
		return (handle_key_move(keycode));
	if (keycode == KEY_HOME || keycode == KEY_END)
		return (handle_home_end(keycode));
	if (keycode == CLS)
		return (clear_line());
}
