/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:39:10 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/27 15:39:45 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*destrocter(t_list *result, t_list *ret)
{
	if (result)
		ft_lstclear(&result, ft_free);
	return (ret);
}

static int	new_arg(t_list **target, char *value)
{
	if (!ft_malloc((void **)target, sizeof(t_list)))
		return (-1);
	(*target)->content = normalize(&value, NORMALIZE_CMD);
	if ((*target)->content == NULL)
	{
		ft_free((*target));
		return (-1);
	}
	return (0);
}

t_list	*parse_arg(t_list *args)
{
	t_list	*result;
	t_list	**curr;

	curr = &result;
	while (args)
	{
		if (new_arg(curr, args->content) == -1)
			return (destrocter(result, PARSE_MALLOC));
		args = args->next;
		curr = &(*curr)->next;
	}
	return (result);
}