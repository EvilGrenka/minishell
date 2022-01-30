/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:37:20 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 19:37:52 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envp_value(char *name)
{
	char	*result;
	t_list	*env;

	env = get_envp(name, g_sh.envp);
	if (!env || !ft_strchr(env->content, '='))
		result = ft_strdup("");
	else
		result = ft_strdup(env->content + ft_strlen(name) + 1);
	return (result);
}