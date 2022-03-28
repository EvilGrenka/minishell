/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree_parser_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:10:46 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:10:46 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_ctr_op_exec(t_ctr_op *ctr, t_check *g)
{
	int		status;

	status = 0;
	status = exec_tree_parser(ctr->left, g);
	if (ctr->type == FT_AND && status != 0)
		return (status);
	if (ctr->type == FT_OR && status == 0)
		return (status);
	status = exec_tree_parser(ctr->right, g);
	return (status);
}

int	exec_tree_parser(t_AST *cmds, t_check *g)
{
	if (cmds->type == FT_CMD && cmds->data)
		return (builtin_parser(cmds->data, g));
	if (cmds->type == FT_PIPE)
		return (ft_pipe_exec(cmds->data, g));
	if (cmds->type == FT_REDIRECT)
		return (ft_redir_exec(cmds->data, g));
	if (cmds->type == FT_CTR_OP)
		return (ft_ctr_op_exec(cmds->data, g));
	return (SUCCESS);
}
