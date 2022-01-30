/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:22:44 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:52:47 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_BONUS_H
# define CURSOR_BONUS_H

void	clear_line(void);
void	cursor_ctrl_left(void);
void	cursor_ctrl_right(void);
void	cursor_left(void);
void	cursor_right(void);
void	delete_char(void);
void	delete_line(void);
int		putchar_tc(int tc);

#endif