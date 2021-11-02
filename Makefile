# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:28:09 by amarchal          #+#    #+#              #
#    Updated: 2021/09/23 12:28:22 by amarchal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS=./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS=$(SRCS:.c=.o)
HDRS=./includes/
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs libft.a $(OBJS)
		
clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.c.o: $(SRCS)
	$(CC) -c $(CFLAGS) -I $(HDRS) $< -o $(<:.c=.o)

.PHONY:	all clean fclean re 
