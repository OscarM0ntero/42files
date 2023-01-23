# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:09:54 by omontero          #+#    #+#              #
#    Updated: 2023/01/23 14:18:52 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo.a

SRCS =	philo_bonus.c philo_time_bonus.c philo_routine_bonus.c philo_print_bonus.c \
		philo_libft_bonus.c philo_inits_bonus.c philo_atoi_itoa_bonus.c \
		philo_death_bonus.c

OBJ = ${SRCS:.c=.o}

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra


${NAME}:	${OBJ}
			@ar -rc ${NAME} ${OBJ}
			${CC} $(FLAGS) ${SRCS} -o philo_bonus
			@${RM} *.o
			@${RM} *.a

all:	${NAME}

bonus:	all

clean:
		@${RM} ${OBJS} philo.dSYM
		@${RM} ${NAME}
		@${RM} *.o

fclean:	clean
		@${RM} ${NAME}
		@${RM} philo_bonus
		@${RM} *.o

re: fclean all

.PHONY: re fclean clean all
