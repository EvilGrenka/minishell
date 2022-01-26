# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 12:38:13 by rnoriko           #+#    #+#              #
#    Updated: 2022/01/26 13:31:40 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

AR = ar
ARFLAGS = crs

CC = clang
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRC_DIR = sources
INC_DIR = includes
OBJ_DIR = objects

HEADERS = $(addprefix $(INC_DIR)/, get_next_line.h)
SRCS	= $(addprefix $(SRCS_DIR)/, get_next_line.c \
			get_next_line_utils.c)

vpath %.c $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS)
	@printf "🧹 Cleaning $(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "🧹 Cleaning $(NAME)\n"

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "🚧 Create $@ from $<\n"

$(NAME) : $(HEADERS) $(OBJS)
	@printf "🚀 Successfully Created $(NAME)'s Object files!\n"
	@printf "📚 Archiving! $@\n"
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@printf "🎉 Successfully Archived $@!\n"

.PHONY: all clean fclean re
