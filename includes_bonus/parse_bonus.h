/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:21:46 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:51:11 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "minishell_bonus.h"

# define PARSE_ERROR_COUNT	5
# define PARSE_MALLOC		0
# define PARSE_MALLOC_MSG	"Memory allocation failure\n"
# define PARSE_INVAILD		1
# define PARSE_INVAILD_MSG	"invaild command\n"
# define PARSE_UNEXPECT		2
# define PARSE_UNEXPECT_MSG	"syntax error near unexpected token\n"
# define PARSE_NOTTHING		3
# define PARSE_CMD_NONE		4
# define PARSE_CMD_NONE_MSG	"command not found: "
# define PARSE_WILDCARD		5
# define PARSE_WILDCARD_MSG	"No such file or directory"

# define NORMALIZE_CMD	0
# define NORMALIZE_ARG	1

# define NO_COLOR "\e[0m"
# define TEXT_COLOR "\e[38;2;255;121;198m"
# define VALUE_COLOR "\e[38;2;189;147;249m"

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

t_list	*parse_line(char *line);
char	*parse_cmd(char *cmd);
t_list	*parse_arg(t_list *args);
char	*normalize(char **token, int type);

void	print_parse_err(t_list *err);
void	free_ast(void *data);
void	free_redirect(t_redirect *redirect);
void	free_ctr_op(t_ctr_op *ctr);
void	free_pipe(t_pipe *pipe);
void	free_cmd(t_cmd *cmd);

char	*get_token(char **line);
char	*get_static_token(char **line, int *status);
t_list	*lexical_analyzer(char *line);
t_list	*syntax_analyzer(t_list *type);

t_AST	*syntax_cmd(t_list **token);
t_AST	*syntax_ast(t_list **token);

void	print_ast(t_AST	*ast, int depth);
void	print_depth(int depth);

int		is_wildcard(char *str);

#endif
