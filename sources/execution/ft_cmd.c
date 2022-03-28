/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:41:05 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:41:06 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int		status;

	if (ft_strcmp(cmds->cmd, "cd") == 0)
		status = ft_cd(cmds->args);
	else if (ft_strcmp(cmds->cmd, "echo") == 0)
		status = ft_echo(cmds->args);
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		status = ft_env();
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		status = ft_export(cmds->args);
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		status = ft_unset(cmds->args);
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
		status = ft_exit(cmds->args);
	else
		status = ft_cmd_set(cmds, g);
	return (status);
}
