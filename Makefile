# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 19:24:07 by agrimald          #+#    #+#              #
#    Updated: 2023/10/04 20:58:06 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CGLAGS = -Wall -Werror -Wextra 
RM = rm -rf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS_SERVER = server.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = client.c
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

.PHONY: all clean fclean re

all: libs $(SERVER) $(CLIENT)

libs:
	make -C $(LIBFT_PATH)

$(SERVER): $(OBJ_SERVER) $(LIBFT) libft/libft.h Makefile
		$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER) 
		
$(CLIENT): $(OBJ_CLIENT) $(LIBFT) libft/libft.h Makefile
		$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT) 

$(OBJ_SERVER): $(SRCS_SERVER) libft/libft.h
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT): $(SRCS_CLIENT) libft/libft.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		make -C $(LIBFT_PATH) clean 
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		make -C $(LIBFT_PATH) fclean
		$(RM) $(SERVER) $(CLIENT)
		@echo "\nClean Cliend and Server!!\n:D"

re: fclean all
