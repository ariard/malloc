# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2017/03/12 15:40:04 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft_malloc_$HOSTTYPE.so
CC		=	gcc
AR		=	ar -rc
MKDIR		=	mkdir -p
RM		=	/bin/rm -rf

FLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR   = libft/
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
malloc_init.c\
malloc.c

SRCS 		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(uname -m)_$(uname -s)
endif

all: 
	gcc -Wall -Wextra -Werror -I includes/ -c src/malloc.c src/malloc_init.c\
		src/bin_add.c src/bin_check.c src/bin_pack.c src/bin_init.c
	gcc -shared -o $(NAME) ./malloc.o malloc_init.o bin_add.o bin_check.o\
		bin_pack.o bin_init.o
	gcc -I includes/malloc.h main.c libft_malloc_$HOSTTYPE.so libft/libft.a

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJR_DIR)
	$(CC) $(FLAGS) -c $< -o $@\
		-I $(INC_DIR)
	
$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(dir $(OBJS))
clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

maintest: all
	gcc -I includes/malloc.h main.c libft_malloc_OSTTYPE.so libft/libft.a

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
