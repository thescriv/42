# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 23:24:18 by tescriva          #+#    #+#              #
#    Updated: 2018/11/14 18:10:26 by thescriv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	src/fdf.c\
		src/ft_draw.c\
		src/key.c\
		src/projection.c\

OBJ =	fdf.o\
 		ft_draw.o \
		key.o \
		projection.o \

LIB =	libft/libft.a mlx/libmlx.a\

FLAG = -Wall -Werror -Wextra

MEM = -fsanitize=address

all : $(NAME)

lib :
	make re -C libft/

$(NAME) :
	@gcc $(FLAG) -c $(SRC)
	@make -C libft
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB) -framework OpenGL -framework AppKit
	@rm -rf $(OBJ)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf fdf

re : fclean all
