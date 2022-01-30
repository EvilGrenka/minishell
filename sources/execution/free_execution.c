/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:12 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 20:48:13 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		free_pipe(g->pipe_fd);
}

void	free_pipe(void *data)
{
	t_pi_fd	*pipe;

	pipe = data;
	if (pipe)
		ft_free(pipe);
}