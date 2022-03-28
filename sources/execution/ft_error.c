/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:41:11 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:41:12 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_print(char *msg, char *args, char *val)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (args)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(args, STDERR_FILENO);
	}
	if (val)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(val, STDERR_FILENO);
	}
	ft_putchar_fd('\n', 1);
}
