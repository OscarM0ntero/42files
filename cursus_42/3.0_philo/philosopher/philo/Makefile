# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:09:54 by omontero          #+#    #+#              #
#    Updated: 2023/01/23 12:49:45 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo.a

SRCS =	philo.c philo_time.c philo_routine.c philo_print.c philo_libft.c philo_inits.c \
		philo_atoi_itoa.c

OBJ = ${SRCS:.c=.o}

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra


${NAME}:	${OBJ}
			@ar -rc ${NAME} ${OBJ}
			@${CC} $(FLAGS) ${SRCS} -o philo
			@${RM} *.o
			@${RM} *.a

all:	${NAME}

clean:
		@${RM} ${OBJS} philo.dSYM
		@${RM} ${NAME}
		@${RM} *.o

fclean:	clean
		@${RM} ${NAME}
		@${RM} philo
		@${RM} *.o

re: fclean all

.PHONY: re fclean clean all
