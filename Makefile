# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2017/03/10 20:30:27 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft_malloc_$HOSTTYPE.so
CC		=	gcc
AR		=	ar -rc
MKDIR		=	mkdir -p
RM		=	/bin/rm -rf

FLAGS		=	-Wall -Wextra -Werror

SRC_DIR		= 	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
malloc_init.c\
malloc.c

SRCS 		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(uname -m)_$(uname -s)
endif

all:
	make -j $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	echo hello
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJR_DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)
	
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(dir $(OBJS))
clean:
	$(RM) $(NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
