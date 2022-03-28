/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:20:50 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:20:53 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_BONUS_H
# define BUILTIN_BONUS_H

# include "minishell_bonus.h"

int		ft_echo(t_list *args);
int		ft_cd(t_list *args);
int		ft_export(t_list *args);
int		compare(t_list *a, t_list *b);
int		ft_unset(t_list *args);
int		ft_env(void);
int		ft_pwd(void);
int		ft_exit(t_list *args);

#endif
