# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 11:26:29 by sde-oliv          #+#    #+#              #
#    Updated: 2024/12/19 12:04:01 by sde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_EXEC = mainftprintf.out	
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_putnbr2.c ft_putstr2.c ft_putptr.c\
ft_putnbr_base.c ft_strlen.c
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