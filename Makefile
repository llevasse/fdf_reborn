# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/03/20 11:00:02 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Werror -Wextra

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

NAME			=	fdf.a

EXECUTABLE		=	fdf

%.o: %.c 
					gcc ${FLAGS} -I includes -c $< -o ${<:.c=.o} -lmlx -lXext -lX11 -lm
					
${NAME}:		${OBJS} includes/fdf.h Makefile
					make -C libft 
					ar rcs ${NAME} libft/libft.a libmlx_Linux.a libmlx.a ${OBJS}
					gcc ${NAME} -o ${EXECUTABLE} -lmlx -lXext -lX11 -lm

all:			${NAME}

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
