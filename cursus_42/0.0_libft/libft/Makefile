# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oscar <oscar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/04/27 10:46:04 by oscar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = first_libc.c second_libc.c third_libc.c fourth_libc.c fifth_libc.c sixth_libc.c
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

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
