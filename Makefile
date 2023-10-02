# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 19:24:07 by agrimald          #+#    #+#              #
#    Updated: 2023/10/02 21:28:28 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CGLAGS = -Wall -Werror -Wextra 
RM = rm -rf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/bin/libft.a

SRCS_SERVER = server.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = client.c
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -s -C $(LIBFT_PATH)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@ -L$(LIBFT_PATH) -lft

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@ -L$(LIBFT_PATH) -lft

$(OBJ_SERVER): $(SRCS_SERVER)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT): $(SRCS_CLIENT)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) clean -s -C $(LIBFT_PATH)
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		$(MAKE) fclean -s -C $(LIBFT_PATH)
		$(RM) $(SERVER) $(CLIENT)
		@echo "\nClean Cliend and Server!!\n:D"

re: fclean all
