/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:21:54 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:56:43 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_BONUS_H
# define UTILITIES_BONUS_H

# include "minishell_bonus.h"

int		getch(void);
void	print_ps(void);
void	print_ps1(void);
void	print_ps2(void);
void	get_line(void);
void	handle_key_input(int keycode);
void	handle_history(int keycode);

int		is_special_key(int keycode);
int		is_delete(int keycode);
int		is_arrow_left_right(int keycode);
int		is_arrow_up_down(int keycode);
int		is_eof(int keycode);

void	set_handle_signal(void);

#endif
