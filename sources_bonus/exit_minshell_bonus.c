/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minshell_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:43:41 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 02:15:43 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	free_cmd_history(t_history	*cmd)
{
	t_history	*tmp;

	while (cmd)
	{
		tmp = cmd->prev;
		ft_free(cmd->cmd);
		ft_free(cmd->edit_cmd);
		ft_free(cmd);
		cmd = tmp;
	}
}

void	exit_minishell(int exitcode)
{
	ft_lstclear(&g_sh.envp, ft_free);
	free_cmd_history(g_sh.cmd);
	exit(exitcode);
}