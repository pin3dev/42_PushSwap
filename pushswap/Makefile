# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 22:31:43 by ivbatist          #+#    #+#              #
#    Updated: 2024/10/01 00:41:45 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

################################################################################
# 						Compiler and Flags	Variables						   #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
RMD = rm -rf

################################################################################
# 							Dir	Path	Variables 							   #
################################################################################

SRC_DIR = src
OBJ_DIR = obj

################################################################################
# 							Files	Path	Variables 						   #
################################################################################

SRC     = $(SRC_DIR)/push_swap.c $(SRC_DIR)/main.c \
		  $(SRC_DIR)/node_markers.c $(SRC_DIR)/numb_checker.c \
          $(SRC_DIR)/op_general.c $(SRC_DIR)/op_a.c $(SRC_DIR)/op_b.c $(SRC_DIR)/op_ab.c \
          $(SRC_DIR)/algo_going.c $(SRC_DIR)/algo_back.c $(SRC_DIR)/algo_sorting.c \
          $(SRC_DIR)/utils_nodes.c $(SRC_DIR)/utils_stack.c $(SRC_DIR)/utils_checkers.c $(SRC_DIR)/utils.c
		  
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

################################################################################
# 							Libft Variables 								   #
################################################################################

LIBFT_DIR = ../../42_Libft/libft 
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = git@github.com:pin3dev/42_Libft.git

################################################################################
# 							Manual	Targets		 							   #
################################################################################

all: $(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RMD) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "PushSwap object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RMD) ../../42_Libft
	@echo "$(NAME) removed"

re: fclean all

################################################################################
# 						Auto Targets 				 						   #
################################################################################
 
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@if [ ! -d ../../42_Libft ]; then \
		echo "Cloning libft from pin3dev repo..."; \
		git clone $(LIBFT_REPO) ../../42_Libft; \
	fi
	@$(MAKE) bonus -C $(LIBFT_DIR)

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re
