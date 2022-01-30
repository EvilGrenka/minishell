/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:41:33 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 19:42:18 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*new_envp(char *value)
{
	t_list	*reuslt;

	if (!ft_malloc((void **)&reuslt, sizeof(t_list)))
		return (NULL);
	reuslt->content = value;
	return (reuslt);
}

int	set_envp(char *value)
{
	t_list	*envp;

	if (g_sh.envp == NULL)
	{
		g_sh.envp = new_envp(value);
		if (g_sh.envp == NULL)
			return (MALLOC_FAIL);
		return (SUCCESS);
	}
	envp = get_envp(value, g_sh.envp);
	if (envp)
	{
		ft_free(envp->content);
		envp->content = value;
		return (SUCCESS);
	}
	envp = ft_lstlast(g_sh.envp);
	envp->next = new_envp(value);
	if (envp->next == NULL)
		return (MALLOC_FAIL);
	return (SUCCESS);
}