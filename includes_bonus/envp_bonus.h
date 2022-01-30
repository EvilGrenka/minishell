/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:38:46 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:53:02 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_BONUS_H
# define ENVP_BONUS_H

# include "minishell_bonus.h"

char	*get_envp_value(char *name);
t_list	*get_envp(char *name, t_list *envp);
int		remove_envp(char *value);
int		set_envp(char *env);

#endif