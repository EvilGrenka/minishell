/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:43:40 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 21:03:00 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

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
	t_dlist		*pipe_fd;
}	t_check;

// builtin_parser.c
int		builtin_parser(t_cmd *cmds, t_check *g);

// execution_cmds.c
int		exec_cmd(t_list *ASTs);

// exec_tree_parser.c
int		exec_tree_parser(t_AST *cmds, t_check *g);

// fork.c
int		builtin_cmd_set(t_cmd *cmds, t_check *g);
int		builtin_pipe_set(t_cmd *cmds, t_check *g);
int		ft_cmd_set(t_cmd *cmds, t_check *g);

// free_exec.c
int		ft_free_cmd(t_cmd *new_cmd, int ret);
void	free_g(t_check *g);
void	free_pipe(void *data);

// ft_cmd.c
int		ft_cmd_exec(t_cmd *cmds, t_check *g);

// ft_error.c
void	ft_error_print(char *msg, char *args, char *val);

// handle_status.c
int		handle_status(int status);

// heredoc.c
int		heredoc(char *eof);

// make_cmd.c
int		parse_cmd_err_check(char *args, char *print_args);
int		ft_make_cmd(char *cmd, t_list *args_lst);

// parse_cmd.c
t_list	*parse_cmd_args(t_list *args_lst, t_check *g);
t_cmd	*parse_t_cmd(t_cmd *cmds, int *status, t_check *g);

// pipe.c
void	ft_pipe_connect(int *status, t_check *g);
void	ft_pipe_write_close(t_check *g, int check);
void	ft_pipe_close(t_check *g);
int		ft_pipe_exec(t_pipe	*pipes, t_check *g);

// redirection.c
int		ft_redir_connect(t_check *g, int check);
int		ft_redir_close(t_check *g);
int		ft_redir_exec(t_redirect *redir, t_check *g);

#endif