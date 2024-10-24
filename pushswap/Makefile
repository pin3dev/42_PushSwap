# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 22:31:43 by ivbatist          #+#    #+#              #
#    Updated: 2024/10/25 00:56:56 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m
BKGRAY=\033[47;90m
BKGRAYGREEN=\033[1;92m
BKGRAYRED=\033[1;91m

################################################################################
# 									Executable	 	 						   #
################################################################################

NAME = push_swap

################################################################################
# 							Dir	Path	Variables 							   #
################################################################################

SRC_DIR = src
OBJ_DIR = obj

################################################################################
# 						Compiler and Flags	Variables						   #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I inc -I $(LIBFT_DIR)/inc
RM = rm -f
RMD = rm -rf

################################################################################
# 							Libft Variables 								   #
################################################################################

LIBFT_DIR = ../../42_Libft/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = git@github.com:pin3dev/42_Libft.git

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
# 							Manual	Targets		 							   #
################################################################################

all: $(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJ)
	@if [ -d "$(OBJ_DIR)" ]; then $(RMD) $(OBJ_DIR); fi
	@echo "${BKGRAY}PushSwap:${BKGRAYRED}- Obj${RESET}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${BKGRAY}PushSwap: ${BKGRAYRED}- Exec${RESET}"

re: fclean all

################################################################################
# 							Dependencies Targets							   #
################################################################################

$(LIBFT):
	@if [ ! -d ../../42_Libft ]; then \
		git clone $(LIBFT_REPO) ../../42_Libft > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}Libft:${RESET} "; 
	@$(MAKE) -C $(LIBFT_DIR) bonus

################################################################################
# 						Auto Targets 				 						   #
################################################################################

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft & \
	./gui_load.sh "PushSwap"
	@wait

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re
