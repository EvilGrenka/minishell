/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:13:01 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 02:11:09 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	getch(void)
{
	static int	i = 0;
	static char	c[4] = {0, 0, 0, 0};

	if (i > 0 && i < 4 && c[i])
		return (c[i++]);
	i = 0;
	if (g_sh.read_fd > 0)
		close(g_sh.read_fd);
	g_sh.read_fd = dup(STDIN_FILENO);
	ft_memset(&c, 0, sizeof(c));
	tcsetattr(g_sh.read_fd, TCSANOW, &g_sh.term_sh);
	read(g_sh.read_fd, &c, sizeof(c));
	tcsetattr(g_sh.read_fd, TCSANOW, &g_sh.term_ori);
	close(g_sh.read_fd);
	g_sh.read_fd = -1;
	if (!ft_isprint(c[0]))
		return (c[0] | c[1] << 8 | c[2] << 16 | c[3] << 24);
	i = 1;
	return (c[0]);
}