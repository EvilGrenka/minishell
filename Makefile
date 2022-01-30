# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 17:03:44 by rnoriko           #+#    #+#              #
#    Updated: 2022/01/31 00:51:52 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror
CLIBFLAGS = -lncurses

RM = rm
RMFLAGS = -rf

INC_DIR = includes
SRC_DIR = sources
OBJ_DIR = objects

# libft
LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/includes
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_INC_DIR)

HEADERS = $(addprefix $(INC_DIR)/, \
	builtin.h \
	cursor.h  \
	envp.h  \
	execution.h  \
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
	parse_args.c \
	parse_cmds.c \
	parse_line.c  \
	parse_utilities.c  \
	print_AST.c \
	syntax_analyzer.c \
	syntax_AST.c  \
	syntax_cmds.c  \
	tokenizer.c \
)

EXECUTION_DIR = $(SRC_DIR)/execution
EXECUTION_SRC = $(addprefix $(EXECUTION_DIR)/,	\
	builtin_parser.c  \
	execution_cmds.c  \
	execution_tree_parser.c  \
	fork.c  \
	free_execution.c \
	ft_cmds.c  \
	ft_error.c  \
	handle_status.c \
	heredoc.c \
	make_cmds.c  \
	parse_t_cmds.c \
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
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "\e[1K\r🔮 Create $@ from $<"

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@printf "\n🪧 $@'s object files was created!\n"
	@printf "📜 Create $@$!\n"
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@
	@printf "🧶 $@ executable file was created!\n"


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