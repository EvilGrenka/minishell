/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_cmds_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:44:48 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:29:33 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	exec_cmd(t_list *ASTs)
{
	int		status;
	t_check	g;

	status = 0;
	while (ASTs)
	{
		ft_memset(&g, 0, sizeof(t_check));
		g.save_in = -1;
		g.save_out = -1;
		status = exec_tree_parser(ASTs->content, &g);
		free_g(&g);
		ASTs = ASTs->next;
	}
	return (status);
}