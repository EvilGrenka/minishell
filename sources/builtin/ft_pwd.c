/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:06:36 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/29 16:07:25 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	name[PATH_MAX];
	int		status;

	status = 0;
	if (getcwd(name, PATH_MAX) == NULL)
	{
		ft_error_print("pwd", NULL, strerror(errno));
		return (FAIL);
	}
	else
		ft_putendl_fd(name, STDOUT_FILENO);
	return (status);
}