/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:21:01 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:21:01 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_BONUS_H
# define CURSOR_BONUS_H

# include "minishell_bonus.h"

int		putchar_tc(int tc);
void	delete_line(void);
void	delete_char(void);
void	cursor_left(void);
void	cursor_right(void);
void	cursor_ctrl_left(void);
void	cursor_ctrl_right(void);
void	clear_line(void);

#endif
