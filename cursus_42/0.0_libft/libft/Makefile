# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oscar <oscar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/04/27 10:10:07 by oscar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = first_libc.c second_libc.c third_libc.c fourth_libc.c fifth_libc.c sixth_libc.c
OBJS = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -fPIC -Wall -Werror -Wextra $(SRC)
	gcc -shared -o libft.so $(OBJS)
