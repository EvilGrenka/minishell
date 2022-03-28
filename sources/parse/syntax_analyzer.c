/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:21:42 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:38:07 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_token(t_list *token)
{
	t_list	*curr;

	curr = token;
	while (curr)
	{
		ft_free(((t_token *)curr->content)->value);
		ft_free(curr->content);
		token = curr;
		curr = curr->next;
		ft_free(token);
	}
}

static t_list	*destructor(t_AST *AST, t_list *ASTs, t_list *token)
{
	free_token(token);
	if (ASTs)
		ft_lstclear(&ASTs, free_ast);
	if (AST)
		free_ast(AST);
	return (PARSE_MALLOC);
}

static int	analyzer(t_list *curr_token, t_list **curr)
{
	t_AST	*ast;

	while (curr_token)
	{
		if (curr_token)
			curr_token = curr_token->next;
		if (curr_token == NULL)
			break ;
		ast = syntax_ast(&curr_token);
		(*curr)->next = ft_lstnew(ast);
		if ((*curr)->next == NULL)
			return (0);
		*curr = (*curr)->next;
	}
	return (1);
}

t_list	*syntax_analyzer(t_list *token)
{
	t_list	*curr_token;
	t_list	*asts;
	t_list	*curr;
	t_AST	*ast;

	curr_token = token;
	asts = NULL;
	ast = syntax_ast(&curr_token);
	if (ast == NULL)
		destructor(ast, asts, token);
	asts = ft_lstnew(ast);
	if (asts == NULL)
		destructor(ast, asts, token);
	curr = asts;
	if (!analyzer(curr_token, &curr))
		return (destructor(ast, asts, token));
	free_token(token);
	return (asts);
}
