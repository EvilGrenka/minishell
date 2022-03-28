/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:20:02 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 12:23:35 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPE_H
# define MINISHELL_TYPE_H

typedef struct s_history
{
	char				*cmd;
	char				*edit_cmd;
	struct s_history	*next;
	struct s_history	*prev;
}	t_history;

typedef struct s_minishell
{
	int				signal;
	int				status;
	int				isps2;
	int				pid;
	int				eof;
	int				read_fd;
	char			*line;
	t_history		*cmd;
	t_history		*history;
	int				cmd_i;
	int				cmd_s;
	t_list			*envp;
	struct termios	term_sh;
	struct termios	term_ori;
}	t_minishell;

# define FT_CMD			1
# define FT_PIPE		2
# define FT_REDIRECT	3
# define FT_CTR_OP		4

typedef struct s_AST
{
	int		type;
	void	*data;
}	t_AST;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

typedef struct s_pipe
{
	t_AST	*left;
	t_AST	*right;
}	t_pipe;

# define FT_FD_IN		1
# define FT_FD_OUT		2
# define FT_FD_APPEND	3
# define FT_FD_HEREDOC	4

typedef struct s_redirect
{
	int		type;
	t_AST	*ast;
	char	*file;
}	t_redirect;

# define FT_OR	1
# define FT_AND	2

typedef struct s_ctr_op
{
	int		type;
	t_AST	*left;
	t_AST	*right;
}	t_ctr_op;

#endif
