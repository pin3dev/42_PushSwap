# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 22:31:43 by ivbatist          #+#    #+#              #
#    Updated: 2023/05/17 23:42:29 by ivbatist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
HDRS 	= push_swap.h
SRC 	= push_swap.c check_algorithm.c check_numbers.c ft_atoi_ps.c \
	  ft_split_functions.c general_operations.c operations_a.c \
	  operations_b.c operations_ab.c outward_algorithm.c \
	  return_algorithm.c sort_algorithm.c utilities_check_main.c \
	  utilities_list.c utilities_return.c
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
