# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 22:31:43 by ivbatist          #+#    #+#              #
#    Updated: 2024/08/08 15:08:38 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
HDRS    = inc/push_swap.h
SRC_DIR = srcs/
SRC     = $(SRC_DIR)push_swap.c $(SRC_DIR)check_algorithm.c $(SRC_DIR)check_numbers.c \
          $(SRC_DIR)ft_atoi_ps.c $(SRC_DIR)ft_split_functions.c $(SRC_DIR)general_operations.c \
          $(SRC_DIR)operations_a.c $(SRC_DIR)operations_b.c $(SRC_DIR)operations_ab.c \
          $(SRC_DIR)outward_algorithm.c $(SRC_DIR)return_algorithm.c $(SRC_DIR)sort_algorithm.c \
          $(SRC_DIR)utilities_check_main.c $(SRC_DIR)utilities_list.c $(SRC_DIR)utilities_return.c
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

# Cleans all generated .o files
clean:
	$(RM) $(OBJS)

# Cleans all generated .o and .a files
fclean: clean
	$(RM) $(NAME)

# Cleans all generated .o and .a files + recompiles
re: fclean all

# Phony is a target that will explicitly tell Make to run the function even if you have a file in your directory with the same name
.PHONY: all clean fclean re