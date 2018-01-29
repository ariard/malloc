# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2018/01/29 18:56:15 by ariard           ###   ########.fr        #
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
10_thousand_small_malloc-free.c\
11_ten_big_malloc-free.c\
12_false_addr_free.c\
13_false_addr_realloc.c\
14_memory_corrupt.c\
15_malloc-realloc-free.c\
16_small_malloc-realloc-free.c\
17_big-malloc-realloc-free.c\
18_thousand_tiny_malloc-realloc-free.c\
19_thousand_small-realloc-free.c\
20_ten_big_malloc-realloc-free.c\
21_tiny_small_big_malloc.c\
23_tiny_small_big_malloc-realloc-free.c\
24_hundred_tiny_small_big_malloc-free.c\
25_multibin_tiny_malloc.c\
26_multibin_small_malloc.c\
27_multibin_tiny_malloc-free.c\
30_realloc_savemem.c\
31_multi-thread.c\
32_coalescing_backward.c\
33_coalescing_forward.c\
34_heap_check.c\


SRCS		=	$(SRC_BASE)
BIN			=	$(addprefix $(BIN_DIR), $(SRC_BASE:.c=))


all: $(BIN_DIR) $(BIN)


$(BIN_DIR):
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(dir $(BIN))

$(BIN_DIR)%: %.c
	@$(CC) $(FLAGS) -o $@ $<

fclean:
	@$(RM) $(BIN)
	@$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
