/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:37:52 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 23:03:48 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "minishell.h"

# define NO_COLOR "\e[0m"
# define TEXT_COLOR "\e[38;2;255;121;198m"
# define VALUE_COLOR "\e[38;2;189;147;249m"

# define PARSE_MALLOC_MSG	"Memory allocation failure\n"
# define PARSE_INVAILD_MSG	"invaild command\n"
# define PARSE_UNEXPECT_MSG	"syntax error near unexpected token\n"
# define PARSE_CMD_NONE_MSG	"command not found: "
# define PARSE_WILDCARD_MSG	"No such file or directory"

# define PARSE_ERROR_COUNT	5
# define PARSE_MALLOC		0
# define PARSE_INVAILD		1
# define PARSE_UNEXPECT		2
# define PARSE_NOTTHING		3
# define PARSE_CMD_NONE		4
# define PARSE_WILDCARD		5

# define NORMALIZE_CMD	0
# define NORMALIZE_ARG	1

# define TK_IFS		" \n\t"
# define TK_NONE	0
# define TK_QOUTE	1
# define TK_QOUTES	2
# define TK_ESCAPE	4

# define LX_NONE		0
# define LX_POSSIBLE	1
# define LX_CMD			2
# define LX_ARG			4
# define LX_REDIRECT	8
# define LX_FILE		16
# define LX_PIPE		32
# define LX_CTR_OP		64
# define LX_SEPERATOR	128

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

void    free_CMD(t_cmd *cmd);
void    free_PIPE(t_pipe *pipe);
void    free_CTR_OP(t_ctr_op *ctr);
void    free_REDIRECT(t_redirect *redirect);
void    free_AST(void *data);

int     is_wildcard(char *str);

t_list  *lexical_analyzer(char *line);

char    *normalize(char **token, int type);

t_list    *parse_arg(t_list *args);

char    *parse_cmd(char *cmd);

t_list	*parse_line(char *line);

void    print_parse_err(t_list *err);
void    print_depth(int depth);

void	print_REDIRECT(t_redirect *redirect, int depth);
void	print_CMD(t_cmd *cmd, int depth);
void	print_PIPE(t_pipe *pipe, int depth);
void	print_CTR_OP(t_ctr_op *ctrop, int depth);
void	print_AST(t_AST	*AST, int depth);

t_list   *syntax_analyzer(t_list *type);
t_AST    *syntax_AST(t_list **token);
t_AST    *syntax_cmd(t_list **token);

char    *get_static_token(char **line, int *status);
char	*get_token(char **line);

#endif
