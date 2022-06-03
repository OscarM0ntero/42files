# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/06/03 13:35:40 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	=	ft_printf.c									       
OBJS	=	$(SRCS:.c=.o)
SRC_DIR	=	src/
OBJ_DIR	=	obj/
OBJF	=	.cache_exists
CC		=	gcc
RM		=	rm -f
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror -I.

all:	$(NAME)

$(NAME):	$(OBJS)	
		@make -C libft
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) include -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
		

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C libft

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f libft/libft.a
			
re:			fclean all

.PHONY:		all clean fclean re norm