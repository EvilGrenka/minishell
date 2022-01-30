/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:24:40 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:22:55 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	clear_line(void)
{
	tputs(tgetstr("cl", NULL), 1, putchar_tc);
	print_PS1();
	ft_putstr_fd(g_sh.line, 1);
}
