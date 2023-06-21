# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/06/21 10:36:50 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Werror -Wextra -g -I $(INC_DIR) -I$(MLX_PATH)

MLX_PATH		= minilibx

MLX_FLAG		= -lmlx -lXext -lX11

INC_DIR			=	includes/

SRC_DIR			=	srcs/

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

RED					=	\033[0;31m
GREEN				=	\033[0;32m
NC					=	\033[0m

LIBFT			=	libft/libft.a

NAME			=	art

%.o:			%.c $(LIBFT) Makefile includes/fdf.h
					cc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):		libft fdf includes/fdf.h Makefile
					@echo "$(GREEN)All files compiled succesfully :D$(NC)"
					@norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'
					@norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'

$(LIBFT)::
					@make -sC libft

all:			$(NAME)

fdf::		$(OBJS) $(LIBFT) includes/fdf.h Makefile
					cc -g $(OBJS) $(LIBFT) -Lmlx_linux -Lminilibx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

clean:
					@make -sC libft clean
					@rm -f ${OBJS}

fclean:			clean
					@make -sC libft fclean
					@rm -f ${NAME} ${EXECUTABLE}

re:				fclean all

.PHONY:			all clean fclean re
