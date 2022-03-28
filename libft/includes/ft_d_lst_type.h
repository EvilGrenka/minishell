/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lst_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:31:41 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/27 18:31:46 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_D_LST_TYPE_H
# define FT_D_LST_TYPE_H

# include "libft.h"

typedef struct s_d_list
{
	struct s_d_list	*next;
	struct s_d_list	*prev;
	void			*content;
}				t_d_list;

#endif
