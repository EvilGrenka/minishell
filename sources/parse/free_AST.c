/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_AST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:42:06 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:36:14 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	ft_free(cmd->cmd);
	ft_lstclear(&cmd->args, ft_free);
	ft_free(cmd);
}

void	free_pipe(t_pipe *pipe)
{
	free_ast(pipe->left);
	free_ast(pipe->right);
	ft_free(pipe);
}

void	free_ctr_op(t_ctr_op *ctr)
{
	free_ast(ctr->left);
	free_ast(ctr->right);
	ft_free(ctr);
}

void	free_redirect(t_redirect *redirect)
{
	free_ast(redirect->ast);
	ft_free(redirect->file);
	ft_free(redirect);
}

void	free_ast(void *data)
{
	t_AST	*ast;

	ast = data;
	if (ast->type == FT_CMD && ast->data)
		free_cmd(ast->data);
	else if (ast->type == FT_PIPE)
		free_pipe(ast->data);
	else if (ast->type == FT_CTR_OP)
		free_ctr_op(ast->data);
	else if (ast->type == FT_REDIRECT)
		free_redirect(ast->data);
	ft_free(ast);
}
