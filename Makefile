# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 22:30:38 by ibotnaru          #+#    #+#              #
#    Updated: 2019/08/12 23:45:25 by ibotnaru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCCW = gcc -g -Wall -Werror -Wextra
SRC = *.c
LIBFT = ./libft/libft.a
INCLUDES = -I ./printf.h

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(GCCW) -c $(SRC) $(INCLUDES)
	@ar rc $(NAME) $(OBJECT) ./libft/*.o
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECT)
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
