# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 15:16:17 by thescriv          #+#    #+#              #
#    Updated: 2018/09/24 18:02:12 by thescriv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = thescriv

SRC =	src/Filler.c \
		src/init_map.c \
		src/Setup.c \
		src/Resolve.c \
		libft/gnl/get_next_line.c \

OBJ =	Filler.o init_map.o Setup.o Resolve.o get_next_line.o \

MA = include/gnl/libft

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC) $(UTI) $(ARG)
#	@make -C $(MA) all
	@gcc -Wall -Werror -Wextra -o thescriv.filler $(OBJ) libft/libft.a
	@rm -rf $(OBJ)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf thescriv.filler

re : fclean all
