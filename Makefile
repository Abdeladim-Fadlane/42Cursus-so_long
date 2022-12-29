# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 10:15:21 by afadlane          #+#    #+#              #
#    Updated: 2022/12/29 13:51:17 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = 	so_long.c \
		check_wall.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_split.c \
		check_ber.c \
		check_element.c \
		ft_move.c	\
		move_utils.c \
		so_long_utils.c \
		ft_printf.c \
		ft_printf_utils.c \
		check_path.c 
cc = gcc
OBJ = ${SRC:.c=.o}
all :${NAME}
	
${NAME}: ${OBJ}
	 	${cc} ${CFLAGS} ${OBJ} ${MLX_FLAGS} -o ${NAME}
clean :
		rm -f ${OBJ}
fclean : clean
		rm -f ${NAME}
nor:
	norminette
re : fclean all
