# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 19:23:47 by mhrima            #+#    #+#              #
#    Updated: 2023/01/13 19:47:57 by mhrima           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
#FLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRC = my_malloc_free.c main.c
OUT = a.out
SAN = -fsanitize=address -g3

$(OUT): $(SRC)
	@$(CC) $(FLAGS) $(SRC)
	@./a.out
	@$(RM) *.out


all: $(OUT)

san:
	@$(CC) $(FLAGS) $(SAN) $(SRC)
	@./a.out
	@$(RM) *.out

clean:
	@$(RM) *.out

re: clean all