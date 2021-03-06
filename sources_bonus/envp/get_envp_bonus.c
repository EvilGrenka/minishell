/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:10:00 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:10:01 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

t_list	*get_envp(char *name, t_list *envp)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(name, '=');
	if (ptr)
		len = ptr - name;
	else
		len = ft_strlen(name);
	while (envp)
	{
		if (!ft_strncmp(envp->content, name, len))
		{
			if (*(char *)(envp->content + len) == '=' || \
				*(char *)(envp->content + len) == '\0')
				return (envp);
		}
		envp = envp->next;
	}
	return (NULL);
}
