# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/07/13 17:33:13 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Werror -Wextra -g -I $(INC_DIR) -I$(MLX_PATH)

MLX_PATH		= minilibx

MLX_FLAG		= -lmlx -lXext -lX11

INC_DIR			=	includes/

SRC_DIR			=	srcs/

FILES			=	srcs/fdf.c			\
					srcs/point.c		\
					srcs/point_bis.c	\
					srcs/project.c		\
					srcs/line.c			\
					srcs/matrix.c		\
					srcs/input.c		\
					srcs/init.c			\
					srcs/extra.c		\
					srcs/init_matrix.c

BONUS_FILES		=	srcs/bonus/init_matrix_bonus.c \
					srcs/bonus/init_bonus.c \
					srcs/bonus/extra_bonus.c \
					srcs/bonus/input_bonus.c \
					srcs/bonus/fdf_bonus.c \
					srcs/bonus/point_bonus.c \
					srcs/bonus/point_bis_bonus.c \
					srcs/bonus/colour_bonus.c \
					srcs/bonus/colour_help_bonus.c \
					srcs/bonus/project_bonus.c \
					srcs/bonus/line_bonus.c \
					srcs/bonus/cross_bonus.c \
					srcs/bonus/matrix_bonus.c

OBJS_DIR			=	.OBJS/
OBJS				=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o))
BONUS_OBJS			=	$(addprefix $(OBJS_DIR), $(BONUS_FILES:.c=.o))

RED					=	\033[0;31m
GREEN				=	\033[0;32m
NC					=	\033[0m

LIBFT			=	libft/libft.a

MINILIBX		=	minilibx/libmlx.a

NAME			=	art

$(OBJS_DIR)%.o:	%.c | $(LIBFT) $(OBJS_DIR)  Makefile includes/fdf.h
					cc ${FLAGS} -c $< -o $@

$(NAME):		$(OBJS) libft fdf includes/fdf.h Makefile
					@echo "$(GREEN)All files compiled succesfully :D$(NC)"
					@norminette $(INC_DIR)fdf.h | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'
					@norminette $(SRC_DIR)*.c | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'
					@norminette libft/ | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'

bonus:			$(BONUS_OBJS) libft fdf_bonus includes/fdf_bonus.h Makefile
					@echo "$(GREEN)All files compiled succesfully :D$(NC)"
					@norminette $(INC_DIR)fdf_bonus.h | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'
					@norminette $(SRC_DIR)/bonus/*.c | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'
					@norminette libft/ | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'

$(LIBFT)::
					@make -sC libft

$(MINILIBX):
					@make -sC minilibx

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)srcs
					@mkdir -p $(OBJS_DIR)srcs/bonus

all:			$(NAME)

fdf::			$(MINILIBX) $(OBJS) $(LIBFT) includes/fdf.h Makefile
					cc -g $(OBJS) $(LIBFT) -Lmlx_linux -Lminilibx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

fdf_bonus::		$(MINILIBX) $(BONUS_OBJS) $(LIBFT) includes/fdf.h Makefile
					cc -g $(BONUS_OBJS) $(LIBFT) -Lmlx_linux -Lminilibx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@


clean:
					@make -sC libft clean
					@rm -f ${OBJS} ${BONUS_OBJS}
					@echo "$(GREEN)All object files deleted succesfully :D$(NC)"

fclean:			clean
					@make -sC libft fclean
					@make -sC minilibx clean
					@rm -f ${NAME} fdf fdf_bonus
					@echo "$(GREEN)All exec files deleted succesfully :D$(NC)"

re:				fclean all

.PHONY:			all clean fclean re
