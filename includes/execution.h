/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:46 by rnoriko           #+#    #+#             */
/*   Updated: 2022/03/28 13:33:39 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define PARSE_ARG_ERR	1

# define DUP_ERROR		-1
# define MALLOC_FAIL	-2
# define OPEN_FAIL		-3

# define PIPE_R_ONLY	0
# define PIPE_W_ONLY	1
# define PIPE_R_W		2

# define SUCCESS	0
# define FAIL		-1

typedef struct s_pi_fd
{
	int		pi_read;
	int		pi_write;
	int		check;
}	t_pi_fd;

typedef struct s_check
{
	int			fd_in;
	int			fd_out;
	int			redir_in;
	int			save_in;
	int			save_out;
	int			pipe_cnt;
	int			args_check;
	t_d_list	*pipe_fd;
}	t_check;

int		exec_cmd(t_list *asts);

int		exec_tree_parser(t_AST *cmds, t_check *g);

int		ft_cmd_exec(t_cmd *cmds, t_check *g);

int		ft_cmd_set(t_cmd *cmds, t_check *g);
int		builtin_cmd_set(t_cmd *cmds, t_check *g);
int		builtin_pipe_set(t_cmd *cmds, t_check *g);

int		ft_redir_exec(t_redirect *redir, t_check *g);
int		ft_redir_connect(t_check *g, int check);
int		ft_redir_close(t_check *g);
void	ft_pipe_write_close(t_check *g, int check);
int		heredoc(char *eof);

int		ft_pipe_exec(t_pipe	*pipes, t_check *g);
void	ft_pipe_connect(int *status, t_check *g);
void	ft_pipe_close(t_check *g);

int		ft_make_cmd(char *cmd, t_list *args_lst);
int		parse_cmd_err_check(char *args, char *print_args);

void	ft_error_print(char *msg, char *args, char *val);

int		ft_free_cmd(t_cmd *new_cmd, int ret);
void	free_pipe_data(void *data);
void	free_g(t_check *g);

t_cmd	*parse_t_cmd(t_cmd *cmds, int *status, t_check *g);
t_list	*parse_cmd_args(t_list *args_lst, t_check *g);

int		builtin_parser(t_cmd *cmds, t_check *g);
int		handle_status(int status);

#endif
