/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:09:08 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:56:21 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	clear_line(void)
{
	tputs(tgetstr("cl", NULL), 1, putchar_tc);
	print_ps1();
	ft_putstr_fd(g_sh.line, 1);
}
