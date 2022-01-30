/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:31:55 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 02:06:53 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
		ft_lstclear(&ASTs, free_AST);
	if (AST)
		free_AST(AST);
	return (PARSE_MALLOC);
}

static int	analyzer(t_list *curr_token, t_list **curr)
{
	t_AST	*AST;

	while (curr_token)
	{
		if (curr_token)
			curr_token = curr_token->next;
		if (curr_token == NULL)
			break ;
		AST = syntax_AST(&curr_token);
		(*curr)->next = ft_lstnew(AST);
		if ((*curr)->next == NULL)
			return (0);
		*curr = (*curr)->next;
	}
	return (1);
}

t_list	*syntax_analyzer(t_list *token)
{
	t_list	*curr_token;
	t_list	*ASTs;
	t_list	*curr;
	t_AST	*AST;

	curr_token = token;
	ASTs = NULL;
	AST = syntax_AST(&curr_token);
	if (AST == NULL)
		destructor(AST, ASTs, token);
	ASTs = ft_lstnew(AST);
	if (ASTs == NULL)
		destructor(AST, ASTs, token);
	curr = ASTs;
	if (!analyzer(curr_token, &curr))
		return (destructor(AST, ASTs, token));
	free_token(token);
	return (ASTs);
}