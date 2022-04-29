# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/04/29 09:35:28 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = first_libc.c second_libc.c third_libc.c fourth_libc.c fifth_libc.c sixth_libc.c first_add.c second_add.c
OBJS = $(SRC:.c=.o)
RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
