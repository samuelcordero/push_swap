# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 15:45:24 by sacorder          #+#    #+#              #
#    Updated: 2023/07/25 21:20:59 by sacorder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIB = libft/libft.a
INCLIB = -L libft -lft
NAME = push_swap
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
INCLUDE = inc/push_swap.h
SRC = src/main.c src/utils.c src/sort.c src/move.c src/check_utils.c
OBJ = $(SRC:.c=.o)
RM=/bin/rm -f

all: $(NAME)

$(LIB):
	@make bonus -C ./libft

$(NAME): $(LIB) $(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(INCLIB)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@make clean -C ./libft
	$(RM) $(OBJ)

fclean:
	@make fclean -C ./libft
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re