/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:53 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:57:48 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

t_minishell	g_sh;

static void	minishell(void)
{
	t_list	*asts;

	g_sh.signal = 0;
	print_ps1();
	get_line();
	if (g_sh.line == NULL)
		return ;
	asts = parse_line(g_sh.line);
	if (asts < (t_list *)PARSE_ERROR_COUNT)
		print_parse_err(asts);
	else
	{
		exec_cmd(asts);
		ft_lstclear(&asts, free_ast);
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
