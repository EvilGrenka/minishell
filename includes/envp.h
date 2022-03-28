/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:04 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:19:32 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "minishell.h"

t_list	*get_envp(char *name, t_list *envp);
char	*get_envp_value(char *name);
int		set_envp(char *env);
int		remove_envp(char *value);

#endif
