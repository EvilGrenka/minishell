# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:01:12 by rnoriko           #+#    #+#              #
#    Updated: 2022/01/31 00:50:27 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

INC_DIR = includes
SRC_DIR = sources
OBJ_DIR = objects

HEADERS = $(addprefix $(INC_DIR)/, \
	libft.h		\
	ft_list.h 	\
	ft_string.h	\
	ft_write.h	\
	ft_math.h	\
	ft_type.h	\
	ft_memory.h	\
)

SRC_DLIST_DIR = $(SRC_DIR)/dlist
SRC_DLIST = $(addprefix $(SRC_DLIST_DIR)/, \
	ft_dlstadd_back.c	\
	ft_dlstadd_front.c	\
	ft_dlstclear.c		\
	ft_dlstdelone.c		\
	ft_dlstlast.c		\
	ft_dlstnew.c		\
	ft_dlstsize.c		\
)

SRC_LIST_DIR = $(SRC_DIR)/list
SRC_LIST = $(addprefix $(SRC_LIST_DIR)/, \
	ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c		\
	ft_lstdelone.c		\
	ft_lstiter.c		\
	ft_lstlast.c		\
	ft_lstmap.c			\
	ft_lstnew.c			\
	ft_lstsize.c		\
	ft_lstsort.c		\
	ft_list_to_array.c	\
)

SRC_MATH_DIR = $(SRC_DIR)/math
SRC_MATH = $(addprefix $(SRC_MATH_DIR)/, \
	ft_pow.c	\
	ft_max.c	\
)

SRC_MEMORY_DIR = $(SRC_DIR)/memory
SRC_MEMORY = $(addprefix $(SRC_MEMORY_DIR)/, \
	ft_bzero.c		\
	ft_calloc.c		\
	ft_free_ret.c 	\
	ft_free.c 		\
	ft_memccpy.c	\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_memcpy.c		\
	ft_memmove.c	\
	ft_memset.c		\
	ft_malloc.c		\
)

SRC_STRING_DIR = $(SRC_DIR)/strings
SRC_STRING = $(addprefix $(SRC_STRING_DIR)/, \
	ft_atoi.c		\
	ft_itoa.c		\
	ft_split.c		\
	ft_strappendc.c \
	ft_strchr.c		\
	ft_strdup.c		\
	ft_strjoin_free.c \
	ft_strjoin.c	\
	ft_strlcat.c	\
	ft_strlcpy.c	\
	ft_strlen.c		\
	ft_strmapi.c	\
	ft_strcmp.c		\
	ft_strncmp.c	\
	ft_strndup_move.c \
	ft_strndup.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strskip.c	\
	ft_strtrim.c	\
	ft_substr.c		\
)

SRC_TYPE_DIR = $(SRC_DIR)/type
SRC_TYPE = $(addprefix $(SRC_TYPE_DIR)/, \
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_tolower.c	\
	ft_toupper.c	\
	ft_iseven.c		\
)

SRC_WRITE_DIR = $(SRC_DIR)/write
SRC_WRITE = $(addprefix $(SRC_WRITE_DIR)/, \
	ft_putchar_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
)

SRCS = \
	$(SRC_DLIST)	\
	$(SRC_LIST)		\
	$(SRC_MATH)		\
	$(SRC_MEMORY)	\
	$(SRC_STRING)	\
	$(SRC_TYPE)		\
	$(SRC_WRITE)	

vpath %.c \
	$(SRC_DIR)			\
	$(SRC_DLIST_DIR)	\
	$(SRC_LIST_DIR)		\
	$(SRC_MATH_DIR)		\
	$(SRC_MEMORY_DIR)	\
	$(SRC_STRING_DIR)	\
	$(SRC_TYPE_DIR)		\
	$(SRC_WRITE_DIR)	

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))


all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@printf "🧹 Delete $(NAME)'s object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "🧹 $(NAME) archive was deleted!\n"

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "\e[1K\r🔮 Create $@ from $<"

$(NAME) : $(HEADERS) $(OBJS)
	@printf "\n🪧 $(NAME)'s object files was created!\n"
	@printf "📜 Archiving $@!\n"
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@printf "🧶 Archive $@ successfully was created!\n"

.PHONY: all clean fclean re