/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:21:06 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:21:07 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_BONUS_H
# define ENVP_BONUS_H

# include "minishell_bonus.h"

t_list	*get_envp(char *name, t_list *envp);
char	*get_envp_value(char *name);
int		set_envp(char *env);
int		remove_envp(char *value);

#endif
