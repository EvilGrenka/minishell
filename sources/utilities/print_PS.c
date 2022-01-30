/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_PS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:24:09 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 21:24:35 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_PS(void)
{
	if (g_sh.isps2)
		print_PS2();
	else
		print_PS1();
}

void	print_PS1(void)
{
	ft_putstr_fd(PS1, 1);
}

void	print_PS2(void)
{
	ft_putstr_fd(PS2, 1);
}