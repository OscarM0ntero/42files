# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 14:09:22 by omontero          #+#    #+#              #
#    Updated: 2023/02/03 14:10:25 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone.a

SRCS =	megaphone.cpp

OBJ = ${SRCS:.c=.o}

CC = c++

RM = rm -rf

FLAGS = -Wall -Werror -Wextra


${NAME}:	${OBJ}
			@ar -rc ${NAME} ${OBJ}
			${CC} $(FLAGS) ${SRCS} -o megaphone
			@${RM} *.o
			@${RM} *.a

all:	${NAME}

clean:
		@${RM} ${OBJS} megaphone.dSYM
		@${RM} ${NAME}
		@${RM} *.o

fclean:	clean
		@${RM} ${NAME}
		@${RM} megaphone
		@${RM} *.o

re: fclean all

.PHONY: re fclean clean all
