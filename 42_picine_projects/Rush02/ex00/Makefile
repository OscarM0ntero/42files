# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:12:07 by carmgarc          #+#    #+#              #
#    Updated: 2022/04/06 16:18:07 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = rush-02
SRC = main.c number_to_word.c print_number.c helpers2.c \
	  helpers.c check_number_length.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) && ./rush-02 400042 | cat -e  && ./rush-02 99999999999999999999999999999999 | cat -e && ./rush-02 2000048 | cat -e && ./rush-02 99999259353872278473999999 | cat -e

fclean:
	rm -f $(NAME)

re: fclean all
