# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/06/20 17:25:12 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Werror -Wextra

MLX_PATH		= minilibx

MLX_FLAG		= -lmlx -lXext -lX11

FILES			=	srcs/fdf.c		\
					srcs/point.c	\
					srcs/project.c	\
					srcs/matrix.c	\
					srcs/colour.c	\
					srcs/filling.c  \
					srcs/input.c	\
					srcs/extra.c	\
					srcs/init_matrix.c

OBJS			=	${FILES:.c=.o}

LIBFT			=	libft/libft.a

NAME			=	fdf

%.o:			%.c Makefile includes/fdf.h
					cc -g ${FLAGS} -I includes -I$(MLX_PATH) -c $< -o ${<:.c=.o}
					
${NAME}:		LIBFT ${OBJS} includes/fdf.h Makefile
					cc -g $(OBJS) $(LIBFT) -Lmlx_linux -Lminilibx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

all:			${NAME}

LIBFT:
					@make -sC libft

clean:
					@make -sC libft clean
					@rm -f ${OBJS}

fclean:			clean
					@make -sC libft fclean
					@rm -f ${NAME} ${EXECUTABLE}

re:				fclean all

.PHONY:			all clean fclean re
