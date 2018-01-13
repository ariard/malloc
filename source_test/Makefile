# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2018/01/12 19:19:09 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			=	gcc
AR			=	ar -rc
MKDIR		=	mkdir -p
RM			=	/bin/rm -rf

FLAGS		=	-Wall -Wextra -Werror

BIN_DIR		=	../test/
PATH_LIB	=	-L/Users/ariard/Projects/malloc		

SRC_BASE	= \
00_malloc.c\
01_small_malloc.c\
02_big_malloc.c\
03_thousand_tiny_malloc.c\
04_thousand_small_malloc.c\
05_ten_big_malloc.c\
06_malloc-free.c\
07_small_malloc-free.c\
08_big_malloc-free.c\
09_thousand_tiny_malloc-free.c\
10_thousand_small_malloc-free.c

SRCS		=	$(SRC_BASE)
BIN			=	$(addprefix $(BIN_DIR), $(SRC_BASE:.c=))


all: $(BIN_DIR) $(BIN)


$(BIN_DIR):
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(dir $(BIN))

$(BIN_DIR)%: %.c
	@$(CC) $(PATH_LIB) $(FLAGS) -o $@ $< -lmalloc

	
fclean:
	@$(RM) $(BIN)
	@$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
