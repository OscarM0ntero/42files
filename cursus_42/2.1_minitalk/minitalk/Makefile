# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 19:05:48 by omontero          #+#    #+#              #
#    Updated: 2023/01/11 12:13:17 by omontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : fclean $(LIBFT) $(SERVER) $(CLIENT) clean

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o includes/minitalk.h
	@$(CC) server.o  $(LIBS) -o $@
	
$(CLIENT) : client.o includes/minitalk.h
	@$(CC) client.o $(LIBS) -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)

re: fclean all