# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 17:03:44 by rnoriko           #+#    #+#              #
#    Updated: 2022/03/28 12:18:15 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror
CLIBFLAGS = -lncurses

RM = rm
RMFLAGS = -rf

# libft
LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/includes
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_INC_DIR)


INC_DIR = includes
SRC_DIR = sources
OBJ_DIR = objects

HEADERS = $(addprefix $(INC_DIR)/, \
	builtin.h \
	cursor.h  \
	envp.h  \
	execution.h  \
	minishell_type.h \
	minishell.h \
	parse.h \
	utilities.h	\
)

UTILITIES_DIR = $(SRC_DIR)/utilities
UTILITIES_SRC = $(addprefix $(UTILITIES_DIR)/, \
	get_line.c  \
	getch.c \
	handle_history.c  \
	handle_key_input.c  \
	handle_signal.c \
	is_utilities.c \
	print_PS.c	\
)

CURSOR_DIR = $(SRC_DIR)/cursor
CURSOR_SRC = $(addprefix $(CURSOR_DIR)/, \
	clear_line.c  \
	cursor_ctrl_left.c  \
	cursor_ctrl_right.c \
	cursor_left.c \
	cursor_right.c  \
	delete_char.c \
	delete_line.c \
	putchar_tc.c  \
)

PARSE_DIR = $(SRC_DIR)/parse
PARSE_SRC = $(addprefix $(PARSE_DIR)/,	\
	free_AST.c  \
	is_wildcard.c \
	lexical_analyzer.c  \
	normalize.c \
	parse_arg.c \
	parse_cmd.c \
	parse_line.c  \
	parse_utilities.c  \
	print_AST.c \
	syntax_analyzer.c \
	syntax_AST.c  \
	syntax_cmd.c  \
	tokenizer.c \
)

EXECUTION_DIR = $(SRC_DIR)/execution
EXECUTION_SRC = $(addprefix $(EXECUTION_DIR)/,	\
	builtin_parser.c  \
	exec_cmd.c  \
	exec_tree_parser.c  \
	fork.c  \
	free_exec.c \
	ft_cmd.c  \
	ft_error.c  \
	handle_status.c \
	heredoc.c \
	make_cmd.c  \
	parse_t_cmd.c \
	pipe.c  \
	redirection.c \
)

ENVP_DIR = $(SRC_DIR)/envp
ENVP_SRC = $(addprefix $(ENVP_DIR)/, \
	get_envp_value.c  \
	get_envp.c  \
	remove_envp.c \
	set_envp.c  \
)

BUILTIN_DIR = $(SRC_DIR)/builtin
BUILTIN_SRC = $(addprefix $(BUILTIN_DIR)/,	\
	export_sort.c \
	ft_cd.c \
	ft_echo.c \
	ft_env.c  \
	ft_exit.c \
	ft_export.c \
	ft_pwd.c  \
	ft_unset.c  \
)

ROOT_SRCS = $(addprefix $(SRC_DIR)/,	\
	exit_minshell.c \
	init.c  \
	minishell.c \
)

SRCS = \
	$(ROOT_SRCS)	\
	$(PARSE_SRC)	\
	$(EXECUTION_SRC)	\
	$(UTILITIES_SRC)	\
	$(CURSOR_SRC)	\
	$(ENVP_SRC)	\
	$(BUILTIN_SRC)

vpath %.c \
	$(SRC_DIR)	\
	$(PARSE_DIR)	\
	$(EXECUTION_DIR)	\
	$(UTILITIES_DIR)	\
	$(CURSOR_DIR)	\
	$(ENVP_DIR)	\
	$(BUILTIN_DIR) \


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))


INC_DIR_BONUS = includes_bonus
SRC_DIR_BONUS = sources_bonus

HEADERS_BONUS = $(addprefix $(INC_DIR_BONUS)/, \
	builtin_bonus.h \
	cursor_bonus.h  \
	envp_bonus.h  \
	execution_bonus.h  \
	minishell_bonus.h \
	minishell_type_bonus.h \
	parse_bonus.h \
	utilities_bonus.h	\
)

UTILITIES_DIR_BONUS = $(SRC_DIR_BONUS)/utilities
UTILITIES_SRC_BONUS = $(addprefix $(UTILITIES_DIR_BONUS)/, \
	get_line_bonus.c  \
	getch_bonus.c \
	handle_history_bonus.c  \
	handle_key_input_bonus.c  \
	handle_signal_bonus.c \
	is_utilities_bonus.c \
	print_PS_bonus.c  \
)

CURSOR_DIR_BONUS = $(SRC_DIR_BONUS)/cursor
CURSOR_SRC_BONUS = $(addprefix $(CURSOR_DIR_BONUS)/, \
	clear_line_bonus.c  \
	cursor_ctrl_left_bonus.c  \
	cursor_ctrl_right_bonus.c \
	cursor_left_bonus.c \
	cursor_right_bonus.c  \
	delete_char_bonus.c \
	delete_line_bonus.c \
	putchar_tc_bonus.c  \
)

PARSE_DIR_BONUS = $(SRC_DIR_BONUS)/parse
PARSE_SRC_BONUS = $(addprefix $(PARSE_DIR_BONUS)/,	\
	free_AST_bonus.c  \
	is_wildcard_bonus.c \
	lexical_analyzer_bonus.c  \
	normalize_bonus.c \
	parse_arg_bonus.c \
	parse_cmd_bonus.c \
	parse_line_bonus.c  \
	parse_utilities_bonus.c  \
	print_AST_bonus.c \
	syntax_AST_bonus.c  \
	syntax_analyzer_bonus.c \
	syntax_cmd_bonus.c  \
	tokenizer_bonus.c \
)

EXECUTION_DIR_BONUS = $(SRC_DIR_BONUS)/execution
EXECUTION_SRC_BONUS = $(addprefix $(EXEC_DIR_BONUS)/,	\
	builtin_parser_bonus.c  \
	exec_cmd_bonus.c  \
	exec_tree_parser_bonus.c  \
	fork_bonus.c  \
	free_exec_bonus.c \
	ft_cmd_bonus.c  \
	ft_error_bonus.c  \
	handle_status_bonus.c \
	heredoc_bonus.c \
	make_cmd_bonus.c  \
	parse_t_cmd_bonus.c \
	pipe_bonus.c  \
	redirection_bonus.c \
)

ENVP_DIR_BONUS = $(SRC_DIR_BONUS)/envp
ENVP_SRC_BONUS = $(addprefix $(ENVP_DIR_BONUS)/, \
	get_envp_bonus.c  \
	get_envp_value_bonus.c  \
	remove_envp_bonus.c \
	set_envp_bonus.c  \
)

BUILTIN_DIR_BONUS = $(SRC_DIR_BONUS)/builtin
BUILTIN_SRC_BONUS = $(addprefix $(BUILTIN_DIR_BONUS)/,	\
	export_sort_bonus.c \
	ft_cd_bonus.c \
	ft_echo_bonus.c \
	ft_env_bonus.c  \
	ft_exit_bonus.c \
	ft_export_bonus.c \
	ft_pwd_bonus.c  \
	ft_unset_bonus.c  \
)

ROOT_SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS)/,	\
	exit_minshell_bonus.c \
	init_bonus.c  \
	minishell_bonus.c \
)

SRCS_BONUS = \
	$(ROOT_SRCS_BONUS)	\
	$(PARSE_SRC_BONUS)	\
	$(EXECUTION_SRC_BONUS)	\
	$(UTILITIES_SRC_BONUS)	\
	$(CURSOR_SRC_BONUS)	\
	$(ENVP_SRC_BONUS)	\
	$(BUILTIN_SRC_BONUS)

vpath %.c \
	$(SRC_DIR_BONUS)	\
	$(PARSE_DIR_BONUS)	\
	$(EXECUTION_DIR_BONUS)	\
	$(UTILITIES_DIR_BONUS)	\
	$(CURSOR_DIR_BONUS)	\
	$(ENVP_DIR_BONUS)	\
	$(BUILTIN_DIR_BONUS) \

OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@printf "🧹 Delete $(NAME)'s object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "🧹 $(NAME) executable file was deleted\n"

re : fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(LIBFT_FILE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(INC_DIR_BONUS) -c $< -o $@
	@printf "\e[1K\r🔮 Create $@ from $<"

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@printf "\n🪧 $@'s object files was created!\n"
	@printf "📜 Create $@$!\n"
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@
	@printf "🧶 $@ executable file was created!\n"

bonus : $(LIBFT_FILE) $(HEADERS_BONUS) $(OBJS_BONUS)
	@printf "\n🪧 $@'s minishell object files was created!\n"
	@printf "📜 Create $@$! minishell\n"
	@$(CC) $(CFLAGS) -I $(INC_DIR_BONUS) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS_BONUS) -o $(NAME)
	@printf "🧶 $@ minishell executable file was created!\n"

# libft
lib : libft
lib_fclean : libft_fclean
lib_re : lib_fclean lib

# libft
libft : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

libft_re :
	@make --no-print-directory -C $(LIBFT_DIR) re

libft_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

libft_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean


.PHONY: all clean fclean re bonus \
	lib lib_re	\
	libft libft_clean libft_fclean