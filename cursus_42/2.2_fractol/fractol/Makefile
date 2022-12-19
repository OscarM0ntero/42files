# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/12/07 13:00:06 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL_NAME = fractol
FLAGS = -framework Cocoa -framework OpenGL -framework IOKit-Wall -Wextra -Werror
INC = -Iinclude/ -I$(LIB_DIR)

PUSH_SRC_NAME = push_swap.c push_swap_utils.c push_swap_swap.c push_swap_sorter.c \
				push_swap_sorter_utils.c push_swap_rotate.c push_swap_reverse_rotate.c \
				push_swap_push.c push_swap_sorter_large.c push_swap_sorter_generic.c \
				push_swap_checkval.c

PUSH_OBJ_NAME = $(PUSH_SRC_NAME:.c=.o)
PUSH_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/

all: $(PUSH_NAME)

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(PUSH_OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(PUSH_NAME)

re: fclean all

.PHONY: all clean fclean re