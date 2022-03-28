/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:38:35 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:44:58 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_line(void)
{
	tputs(tgetstr("cl", NULL), 1, putchar_tc);
	print_ps1();
	ft_putstr_fd(g_sh.line, 1);
}
