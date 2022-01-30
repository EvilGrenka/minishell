/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:16:08 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:54:16 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_BONUS_H
# define UTILITIES_BONUS_H

#include "minishell_bonus.h"

void	get_line(void);

int		getch(void);

void	handle_history(int keycode);

void	handle_key_input(int keycode);

void	set_handle_signal(void);

int		is_arrow_up_down(int keycode);
int		is_arrow_left_right(int keycode);
int		is_delete(int keycode);
int		is_eof(int keycode);
int		is_special_key(int keycode);

void	print_PS(void);
void	print_PS1(void);
void	print_PS2(void);

#endif