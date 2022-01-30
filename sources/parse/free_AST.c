/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_AST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:51:36 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/29 15:17:04 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_CMD(t_cmd *cmd)
{
	ft_free(cmd->cmd);
	ft_lstclear(&cmd->args, ft_free);
	ft_free(cmd);
}

void	free_PIPE(t_pipe *pipe)
{
	free_AST(pipe->left);
	free_AST(pipe->right);
	ft_free(pipe);
}

void	free_CTR_OP(t_ctr_op *ctr)
{
	free_AST(ctr->left);
	free_AST(ctr->right);
	ft_free(ctr);
}

void	free_REDIRECT(t_redirect *redirect)
{
	free_AST(redirect->AST);
	ft_free(redirect->file);
	ft_free(redirect);
}

void	free_AST(void *data)
{
	t_AST	*AST;

	AST = data;
	if (AST->type == FT_CMD && AST->data)
		free_CMD(AST->data);
	else if (AST->type == FT_PIPE)
		free_PIPE(AST->data);
	else if (AST->type == FT_CTR_OP)
		free_CTR_OP(AST->data);
	else if (AST->type == FT_REDIRECT)
		free_REDIRECT(AST->data);
	ft_free(AST);
}