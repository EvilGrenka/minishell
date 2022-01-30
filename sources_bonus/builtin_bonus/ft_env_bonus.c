/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:00:17 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:19:18 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_env(void)
{
	t_list	*env;

	env = g_sh.envp;
	while (env)
	{
		if (strchr(env->content, '=') != 0)
			ft_putendl_fd(env->content, STDOUT_FILENO);
		env = env->next;
	}
	return (SUCCESS);
}