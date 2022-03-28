/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_PS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:23:00 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:53:33 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ps(void)
{
	if (g_sh.isps2)
		print_ps2();
	else
		print_ps1();
}

void	print_ps1(void)
{
	ft_putstr_fd(PS1, 1);
}

void	print_ps2(void)
{
	ft_putstr_fd(PS2, 1);
}
