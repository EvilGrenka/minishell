/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_t_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:41:37 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:41:38 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*parse_cmd_args(t_list *args_lst, t_check *g)
{
	t_list	*result;

	if (args_lst)
	{
		result = parse_arg(args_lst);
		if ((long)result == PARSE_MALLOC)
			ft_error_print(PARSE_MALLOC_MSG, NULL, strerror(errno));
		else if ((long)result == PARSE_CMD_NONE)
			ft_error_print(PARSE_CMD_NONE_MSG, NULL, strerror(errno));
		else if (args_lst->content != result->content)
			g->args_check = 1;
		return (result);
	}
	return (NULL);
}

t_cmd	*parse_t_cmd(t_cmd *cmds, int *status, t_check *g)
{
	t_cmd	*result;

	*status = 0;
	if (!ft_malloc((void **)&result, sizeof(t_cmd)))
	{
		*status = PARSE_MALLOC;
		return (result);
	}
	result->cmd = cmds->cmd;
	result->cmd = normalize(&result->cmd, NORMALIZE_CMD);
	if (result->cmd == NULL)
	{
		*status = PARSE_MALLOC;
		return (result);
	}
	if (cmds->args == NULL)
		return (result);
	result->args = parse_cmd_args(cmds->args, g);
	if (result->args <= (t_list *)PARSE_ERROR_COUNT)
		*status = (long)result->args;
	return (result);
}
