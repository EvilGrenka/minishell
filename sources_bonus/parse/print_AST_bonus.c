/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_AST_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:13:44 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:48:22 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	print_redirect(t_redirect *redirect, int depth)
{
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tredirect-> %s%d%s\n", VALUE_COLOR, redirect->type, TEXT_COLOR);
	print_depth(depth);
	printf("\tfile-> %s%s%s\n", VALUE_COLOR, redirect->file, TEXT_COLOR);
	print_depth(depth);
	printf("\tAST->\n");
	if (redirect->ast == NULL)
	{
		print_depth(depth);
		printf("\t%s(NULL)%s\n", VALUE_COLOR, TEXT_COLOR);
	}
	else
		print_ast(redirect->ast, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_cmd(t_cmd *cmd, int depth)
{
	t_list	*curr;

	if (cmd == NULL)
		return ;
	curr = cmd->args;
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tcmd -> \"%s%s%s\"\n", VALUE_COLOR, cmd->cmd, TEXT_COLOR);
	print_depth(depth);
	printf("\targs -> \n");
	while (curr)
	{
		print_depth(depth);
		printf("\t\"%s%s%s\"\n", VALUE_COLOR, (char *)curr->content, TEXT_COLOR);
		curr = curr->next;
	}
	print_depth(depth);
	printf("}\n");
}

void	print_pipe(t_pipe *pipe, int depth)
{
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tPIPE\n");
	print_depth(depth);
	printf("\t%sleft->\n", TEXT_COLOR);
	print_ast(pipe->left, depth + 1);
	print_depth(depth);
	printf("\t%sright->\n", TEXT_COLOR);
	print_ast(pipe->right, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_ctr_op(t_ctr_op *ctrop, int depth)
{
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tControl Operator\n");
	print_depth(depth);
	printf("\ttype-> \"%s%d%s\"\n", VALUE_COLOR, ctrop->type, TEXT_COLOR);
	print_depth(depth);
	printf("\t%sleft->\n", TEXT_COLOR);
	print_ast(ctrop->left, depth + 1);
	print_depth(depth);
	printf("\t%sright->\n", TEXT_COLOR);
	print_ast(ctrop->right, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_ast(t_AST	*ast, int depth)
{
	if (ast->type == FT_CMD)
		print_cmd(ast->data, depth);
	else if (ast->type == FT_PIPE)
		print_pipe(ast->data, depth);
	else if (ast->type == FT_CTR_OP)
		print_ctr_op(ast->data, depth);
	else if (ast->type == FT_REDIRECT)
		print_redirect(ast->data, depth);
	ft_putstr_fd(NO_COLOR, 1);
}
