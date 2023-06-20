# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/06/20 14:06:49 by llevasse         ###   ########.fr        #
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
					srcs/init_matrix.c \
					srcs/debug.c

OBJS			=	${FILES:.c=.o}

LIBFT			=	libft/libft.a

NAME			=	fdf.a

EXECUTABLE		=	fdf

%.o:			%.c Makefile includes/fdf.h
					cc -g ${FLAGS} -I includes -I$(MLX_PATH) -c $< -o ${<:.c=.o}
					
${NAME}:		${OBJS} $(LIBFT) includes/fdf.h Makefile
					cc -g -ggdb $(OBJS) $(LIBFT) -Lmlx_linux -Lminilibx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${EXECUTABLE}

all:			${NAME}

$(LIBFT):
					@make -sC libft

clean:
					make -C libft clean
					rm -f ${OBJS}

fclean:			clean
					rm -f ${NAME} ${EXECUTABLE}

re:				fclean all

VAR				= test_files/42.fdf

alldebug:		bin/$(EXECUTABLE)

run:			cleandebug alldebug
					clear
					./bin/$(EXECUTABLE) $(VAR)

run_test:		cleandebug alldebug
					clear
					./bin/$(EXECUTABLE) test_files/test.fdf
					
run_test100-6:	cleandebug alldebug
					clear
					./bin/fdf test_files/100-6.fdf


run_vs_code: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE)

bin/$(EXECUTABLE): ${FILES} libft/libft.a libmlx_Linux.a libmlx.a
					gcc ${FLAGS} -fsanitize=address -ggdb $^ -o $@ -lmlx -lXext -lX11 -lm

cleandebug:
					-rm ./bin/*

.PHONY:			all clean fclean re
