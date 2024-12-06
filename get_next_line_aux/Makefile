# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:24:51 by sde-oliv          #+#    #+#              #
#    Updated: 2024/12/02 12:24:56 by sde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
NAME_EXEC = mainftprintf.out	
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c
OBJ = $(SRC:.c=.o)
MAIN = main.c
OBJ_MAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr *.o

fclean: clean
	rm -fr $(NAME)

re: fclean all

#testermain

test: all $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(OBJ_MAIN) $(NAME) -o $(NAME_EXEC)

tclean :
	rm -fr *.out
