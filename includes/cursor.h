/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:22:44 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 23:31:50 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "minishell.h"

void	clear_line(void);
void	cursor_ctrl_left(void);
void	cursor_ctrl_right(void);
void	cursor_left(void);
void	cursor_right(void);
void	delete_char(void);
void	delete_line(void);
int		putchar_tc(int tc);

#endif