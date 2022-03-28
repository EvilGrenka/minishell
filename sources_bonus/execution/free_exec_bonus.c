/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:11:08 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:51:56 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_free_cmd(t_cmd *new_cmd, int ret)
{
	if (new_cmd)
	{
		ft_free(new_cmd->cmd);
		if (new_cmd->args > (t_list *)PARSE_ERROR_COUNT)
			ft_lstclear(&new_cmd->args, ft_free);
		free(new_cmd);
	}
	return (ret);
}

void	free_g(t_check *g)
{
	if (g->pipe_fd)
		free_pipe_data(g->pipe_fd);
}

void	free_pipe_data(void *data)
{
	t_pi_fd	*pipe;

	pipe = data;
	if (pipe)
		ft_free(pipe);
}
