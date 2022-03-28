/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:22:47 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:44:27 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int sig)
{
	g_sh.signal = sig;
	ft_putchar_fd('\n', 1);
	if (!g_sh.pid)
	{
		ft_free(g_sh.line);
		g_sh.line = NULL;
		if (!g_sh.isps2)
			print_ps1();
	}
	if (g_sh.read_fd > 0)
	{
		close(g_sh.read_fd);
		g_sh.read_fd = -1;
	}
}

static void	handle_sigquit(int sig)
{
	g_sh.signal = sig;
}

void	set_handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
