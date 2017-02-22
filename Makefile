# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 16:46:21 by ele-cren          #+#    #+#              #
#    Updated: 2017/02/22 11:40:58 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/draw.c srcs/color.c srcs/error.c srcs/event.c srcs/event2.c \
	   srcs/init.c srcs/main.c srcs/mlx.c srcs/utilities.c

OBJ = draw.o color.o error.o event.o event2.o init.o main.o mlx.o utilities.o

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	make -C libft/ all
	gcc -c $(SRCS) $(FLAG) -I includes -I libft/includes
	gcc $(OBJ) -L./libft -lft -lmlx -framework OpenGL -framework AppKit \
		-o $(NAME)

clean : 
	make -C libft clean
	rm -f $(OBJ)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
