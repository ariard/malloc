# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:50:31 by ariard            #+#    #+#              #
#    Updated: 2018/01/24 23:53:37 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft_malloc_$(HOSTTYPE).so
SYM_NAME	=	libft_malloc.so
CC			=	gcc
MKDIR		=	mkdir -p
RM			=	/bin/rm -rf

FLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR   = libft/
LIBFT_LIB	= $(LIBFT_DIR)libft.a
LIBFT_INC	= $(LIBFT_DIR)includes/

TEST_DIR	=	source_test/
MOULI_DIR	=	moulitest/

SRC_DIR		= 	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
bin_add.c\
bin_pack.c\
bin_checkin.c\
bin_range.c\
chunk_init.c\
chunk_coalesce.c\
chunk_search.c\
chunk_find.c\
chunk_merge.c\
chunk_error.c\
chunk_set.c\
chunk_check.c\
thread_set.c\
thread_unset.c\
malloc_init.c\
malloc.c\
free.c\
realloc.c\
align.c\
checksum.c\
log.c\
area_print.c\
db_show_free_mem.c\
db_show_alloc_mem.c\
db_level.c\
db_print_addr.c\
db_print_value.c\

TEST_BASE	= \

SRCS 		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

ifeq ($(HOSTTYPE), )
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all: $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) -shared -o $(NAME) $(OBJS) $(LIBFT_LIB)
	@rm -f $(SYM_NAME)
	@ln -s $(NAME) $(SYM_NAME)
	
main:
	gcc -L/Users/ariard/Projects/malloc -Wall -I includes/ main.c -o main -lmalloc

main-clean:
	rm -f main

re-main: main-clean main

build-test:
	@$(MAKE) -C $(TEST_DIR)

fclean-test:
	@$(MAKE) fclean -C $(TEST_DIR)

re-test:
	@$(MAKE) re -C $(TEST_DIR)

build-mouli:
	@$(MAKE) -C $(MOULI_DIR)

clean-mouli:
	@$(MAKE) fclean -C $(MOULI_DIR)

re-mouli:
	@$(MAKE) re -C $(MOULI_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJR_DIR)
	@$(CC) $(FLAGS) -c $< -o $@\
		-I $(INC_DIR) \
		-I $(LIBFT_INC)

clean:		cleanlib
	rm -rf  $(OBJ_DIR)

cleanlib:
	make -C $(LIBFT_DIR) clean

fclean: clean fcleanlib
	rm -f $(NAME)
	rm -f $(SYM_NAME)

fcleanlib:	cleanlib
	@make -C $(LIBFT_DIR) fclean

re: fclean all

relib: fcleanlib $(LIBFT_LIB)

.PHONY: 	fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
