/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:25:27 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/27 15:28:35 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_list	*parse_line(char *line)
{
	t_list	*result;

	result = lexical_analyzer(line);
	if (result < (t_list *)PARSE_ERROR_COUNT)
		return (result);
	result = syntax_analyzer(result);
	return (result);
}
