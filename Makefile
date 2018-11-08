# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroelle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:27:42 by jroelle           #+#    #+#              #
#    Updated: 2018/11/07 21:01:08 by jroelle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wall -Wextra -Werror
SRCS = main.c ft_*.c
OBJ = main.o ft_*.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
