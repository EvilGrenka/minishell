/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:03 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/31 01:13:27 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_BONUS_H
# define BUILTIN_BONUS_H

# include "minishell_bonus.h"

int		compare(t_list *a, t_list *b);
int		ft_cd(t_list *args);
int		ft_echo(t_list *args);
int		ft_env(void);
int		ft_exit(t_list *args);
int		ft_export(t_list *args);
int		ft_pwd(void);
int		ft_unset(t_list *args);

#endif