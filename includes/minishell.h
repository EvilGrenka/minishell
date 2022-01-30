/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:19:24 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 23:43:55 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>
# include <string.h>
# include <dirent.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include "libft.h"

# define FT_CMD			1
# define FT_PIPE		2
# define FT_REDIRECT	3
# define FT_CTR_OP		4

# define FT_FD_IN		1
# define FT_FD_OUT		2
# define FT_FD_APPEND	3
# define FT_FD_HEREDOC	4

# define FT_OR	1
# define FT_AND	2

# define PARSE_ARG_ERR	1

# define DUP_ERROR		-1
# define MALLOC_FAIL	-2
# define OPEN_FAIL		-3

# define PIPE_R_ONLY	0
# define PIPE_W_ONLY	1
# define PIPE_R_W		2

# define SUCCESS	0
# define FAIL		-1

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
}				t_minishell;

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

typedef struct s_redirect
{
	int		type;
	t_AST	*AST;
	char	*file;
}	t_redirect;

typedef struct s_ctr_op
{
	int		type;
	t_AST	*left;
	t_AST	*right;
}	t_ctr_op;

extern t_minishell	g_sh;

# include "builtin.h"
# include "cursor.h"
# include "envp.h"
# include "execution.h"
# include "parse.h"
# include "utilities.h"

# define TERM_ERROR	"Specify a terminal type with `setenv TERM <yourtype>'.\n"
# define TERM_SUCCES_ERR	"Could not access the termcap data base.\n"
# define TERM_NOT_DEFINE_PART1	"Terminal type `"
# define TERM_NOT_DEFINE_PART2	"' is not defined.\n"

# define PS1	"minishell>"
# define PS2	"> "

# define ARROW_UP		4283163
# define ARROW_DOWN		4348699
# define CTRL_LEFT		25115
# define CTRL_RIGHT		26139
# define ARROW_LEFT		4479771
# define ARROW_RIGHT	4414235
# define DELETE			127
# define EOF_CHAR		'\4'
# define KEY_HOME		4741915
# define KEY_END		4610843
# define CLS			12

void	exit_minishell(int exitcode);
void	init_minishell(char *envp[]);

#endif