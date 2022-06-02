# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by omontero          #+#    #+#              #
#    Updated: 2022/06/02 19:10:37 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c
										       
OBJS	=	$(SRCS:.c=.o)

BONUS	=	ft_printf_bonus.c \

BONUS_OBJS	= 	$(BONUS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I.

NAME	= libft.a


$(NAME):		
	gcc -c $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)
	
bonus: ${OBJS} ${BONUS_OBJS}
	ar rs ${NAME} ${OBJS} ${BONUS_OBJS}

all:	$(NAME)
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus