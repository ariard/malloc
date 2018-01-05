# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2018/01/05 20:59:52 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OS		:= $(shell uname) 
NAME	=	libmalloc.so
CC		=	gcc
AR		=	ar -rc
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

FLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR   	= libft/
LIBFT_LIB	= $(LIBFT_DIR)libft.a
LIBFT_INC	= $(LIBFT_DIR)includes/

SRC_DIR		= 	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
bin_add.c\
bin_check.c\
bin_pack.c\
bin_init.c\
chunk_check.c\
chunk_init.c\
malloc_init.c\
malloc.c

SRCS 		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all: 	
ifeq ($(OS), Linux)
	gcc -c -Wall -Werror -I includes/ -fPIC $(SRCS)
	gcc -shared -o $(NAME) $(SRC_BASE:.c=.o)
	gcc -L/home/user/Projects/malloc -Wall -I includes/ main.c -o main -lmalloc
	export LD_LIBRARY_PATH=/home/user/Projects/malloc
else
	gcc -c -Wall -Werror -I includes/ $(SRCS)
	gcc -shared -o $(NAME) $(SRC_BASE:.c=.o)
	gcc -L/Users/ariard/Projects/malloc -Wall -I includes/ main.c -o main -lmalloc
endif

test: all


$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJR_DIR)
	$(CC) $(FLAGS) -c $< -o $@\
		-I $(INC_DIR)
	
clean:
	@rm *.o

fclean: clean
	@$(RM) $(NAME)

maintest: all
	gcc -I includes/malloc.h main.c libft_malloc_OSTTYPE.so libft/libft.a

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
