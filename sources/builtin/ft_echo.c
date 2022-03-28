/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:37:41 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 19:37:42 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_list *args)
{
	t_list	*curr;
	int		status;

	status = 0;
	if (!args)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	curr = args;
	if (ft_strcmp(curr->content, "-n") == 0)
	{
		status = 1;
		curr = curr->next;
	}
	while (curr)
	{
		ft_putstr_fd(curr->content, STDOUT_FILENO);
		curr = curr->next;
		if (curr)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (status != 1)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
