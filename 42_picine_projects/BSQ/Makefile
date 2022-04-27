# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/04/07 14:40:39 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = main.c matrix_assigners.c checkers.c assist.c assist2.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re: fclean all
