/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:10:31 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:50:49 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	is_builtin(t_cmd *cmds)
{
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (1);
	return (0);
}

int	builtin_parser(t_cmd *cmds, t_check *g)
{
	t_cmd	*result;
	int		check;
	int		status;

	g_sh.pid = 0;
	result = parse_t_cmd(cmds, &status, g);
	if (status != SUCCESS)
		return (ft_free_cmd(result, FAIL));
	check = is_builtin(result);
	if (check == 1 && g->pipe_cnt > 0)
		check = 2;
	if (check == 0)
		status = ft_cmd_exec(result, g);
	else if (check == 1)
		status = builtin_cmd_set(result, g);
	else
		status = builtin_pipe_set(result, g);
	free_cmd(result);
	return (status);
}
