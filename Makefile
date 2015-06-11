# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	fdf
CC		=	gcc
CCO		=	gcc -o
LIB		=	-L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
FLAGS	=	-c -Wall -Werror -Wextra

INC		=	libft/includes/ -I /usr/X11/include/ -I minilibx_macos/

C_FILES	= main.c
C_FILES += get_next_line.c
C_FILES += window.c
C_FILES += parse.c
C_FILES += ft_split.c
C_FILES += key.c
C_FILES += ft_list_push_back.c
C_FILES += render.c
C_FILES += render_line.c

O_FILES	= main.o
O_FILES += get_next_line.o
O_FILES += window.o
O_FILES += parse.o
O_FILES += ft_split.o
O_FILES += key.o
O_FILES += ft_list_push_back.o
O_FILES += render.o
O_FILES += render_line.o

all		: $(NAME)

$(NAME)	:
	@make -C libft/ all
	@make -sC minilibx_macos/ all
	@$(CC) $(FLAGS) -c $(C_FILES) -I $(INC)
	@$(CC) -o $(NAME) $(O_FILES)  $(LIB)

clean	:
	@make -C libft/ clean
	@make -sC minilibx_macos/ clean
	@/bin/rm -f $(O_FILES)

fclean	: clean
	@make -C libft/ fclean
	@make -sC minilibx_macos/ fclean
	@/bin/rm -f $(NAME)

re		: fclean all
