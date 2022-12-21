# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 10:15:21 by afadlane          #+#    #+#              #
#    Updated: 2022/12/21 11:00:18 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = 	so_long.c \
		check_map.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_split.c \
		check_path.c \
		checkelement.c \
		ft_move.c
cc = gcc

all :${NAME}
	
${NAME}: 
	 	${cc} ${CFLAGS} ${SRC} ${MLX_FLAGS} -o ${NAME}
clean :
		rm -f ${OBJ}
fclean : clean
		rm -f ${NAME}
nor:
	norminette
re : fclean all
