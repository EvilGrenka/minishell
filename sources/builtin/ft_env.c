/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:37:49 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:37:49 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
