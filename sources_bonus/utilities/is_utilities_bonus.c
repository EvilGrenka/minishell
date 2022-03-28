/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utilities_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:22 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:15:23 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	is_arrow_up_down(int keycode)
{
	if (keycode == ARROW_UP)
		return (1);
	if (keycode == ARROW_DOWN)
		return (1);
	return (0);
}

int	is_arrow_left_right(int keycode)
{
	if (keycode == ARROW_LEFT)
		return (1);
	if (keycode == ARROW_RIGHT)
		return (1);
	if (keycode == CTRL_LEFT)
		return (1);
	if (keycode == CTRL_RIGHT)
		return (1);
	return (0);
}

int	is_delete(int keycode)
{
	if (keycode == DELETE)
		return (1);
	return (0);
}

int	is_eof(int keycode)
{
	if (keycode == EOF_CHAR)
		return (1);
	return (0);
}

int	is_special_key(int keycode)
{
	if (is_arrow_left_right(keycode) || \
		is_arrow_up_down(keycode) || \
		is_delete(keycode) || \
		keycode == KEY_HOME || \
		keycode == KEY_END || \
		keycode == CLS)
		return (1);
	return (0);
}
