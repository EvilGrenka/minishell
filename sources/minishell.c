/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:44:32 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 21:44:33 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_sh;

static void	minishell(void)
{
	t_list	*ASTs;

	g_sh.signal = 0;
	print_PS1();
	get_line();
	if (g_sh.line == NULL)
		return ;
	ASTs = parse_line(g_sh.line);
	if (ASTs < (t_list *)PARSE_ERROR_COUNT)
		print_parse_err(ASTs);
	else
	{
		exec_cmd(ASTs);
		ft_lstclear(&ASTs, free_AST);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_minishell(envp);
	while (1)
		minishell();
	return (0);
}