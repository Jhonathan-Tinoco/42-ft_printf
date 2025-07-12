# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhodos-s <jhodos-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 15:19:13 by jhodos-s          #+#    #+#              #
#    Updated: 2025/07/11 13:20:13 by jhodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
		SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putuint.c ft_putnbr.c ft_putptr.c ft_puthex.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
