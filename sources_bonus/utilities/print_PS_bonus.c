/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_PS_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:29 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:24:54 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
