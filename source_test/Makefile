# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2018/01/11 22:15:43 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OS		:= $(shell uname) 
CC		=	gcc
AR		=	ar -rc
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

FLAGS		=	-Wall -Wextra -Werror

TEST_DIR	=	source_test/
BIN_DIR		=	../test

SRCS 		=	$(wildcard *.c)

PROGS		=	$(patsubst	%.c, %, $(SRCS))

all: $(PROGS)


$(BIN_DIR):
	@mkdir $(BIN_DIR)

%:	%.c
	$(CC) $(FLAGS) -o $@ $< 
	
clean:
	@rm *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
