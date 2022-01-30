/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:00 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/29 16:04:47 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_with_arg(t_list *arg)
{
	char	*str;
	int		exit_code;

	exit_code = 0;
	str = arg->content;
	while (*str && ft_isdigit(*str))
		exit_code = (exit_code * 10) + *str++ - '0';
	if (*str)
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(arg->content, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	if (arg->next)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit(exit_code);
	return (0);
}

int	ft_exit(t_list *args)
{
	ft_putendl_fd("exit", STDERR_FILENO);
	if (args)
		return (exit_with_arg(args));
	exit(0);
	return (0);
}