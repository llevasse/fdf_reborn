# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/03/02 15:03:58 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Werror -Wextra

FILES			=	srcs/fdf.c							

LIBFT_FILES		=	libft/ft_putstr_fd.c \
					libft/ft_strchr.c \
					libft/ft_memset.c \
					libft/ft_strnstr.c \
					libft/ft_substr.c \
					libft/ft_strlcpy.c \
					libft/ft_bzero.c \
					libft/ft_atoi.c \
					libft/ft_lstadd_back_bonus.c \
					libft/ft_strtrim.c \
					libft/ft_itoa.c \
					libft/ft_lstmap_bonus.c \
					libft/ft_isprint.c \
					libft/ft_toupper.c \
					libft/ft_putnbr_fd.c \
					libft/ft_isdigit.c \
					libft/ft_memmove.c \
					libft/ft_lstiter_bonus.c \
					libft/ft_lstnew_bonus.c \
					libft/ft_isascii.c \
					libft/ft_putchar_fd.c \
					libft/ft_memchr.c \
					libft/ft_strmapi.c \
					libft/ft_memcmp.c \
					libft/ft_lstlast_bonus.c \
					libft/ft_lstclear_bonus.c \
					libft/ft_strdup.c \
					libft/ft_calloc.c \
					libft/ft_isalpha.c \
					libft/ft_lstsize_bonus.c \
					libft/ft_split.c \
					libft/ft_striteri.c \
					libft/ft_strncmp.c \
					libft/ft_strrchr.c \
					libft/ft_putendl_fd.c \
					libft/ft_tolower.c \
					libft/ft_strjoin.c \
					libft/ft_lstdelone_bonus.c \
					libft/ft_strlen.c \
					libft/ft_lstadd_front_bonus.c \
					libft/ft_memcpy.c \
					libft/ft_strlcat.c \
					libft/ft_isalnum.c \
					libft/gnl/get_next_line_bonus.c \
					libft/gnl/get_next_line_utils_bonus.c \
					libft/ft_printf/ft_printf_utils.c \
					libft/ft_printf/ft_printf.c \
					libft/ft_is_in_str.c \

OBJS			=	${FILES:.c=.o} ${LIBFT_FILES:.c=.o}

NAME			=	fdf.a

EXECUTABLE		=	fdf

.c.o:
					gcc ${FLAGS} -c $< -o ${<:.c=.o} -lmlx -lXext -lX11
					
${NAME}:		${OBJS}
					cd	libft;	make libft.a; cd ..; 
					ar rcs ${NAME} ${OBJS};
					gcc ${NAME} -o ${EXECUTABLE} -lm

all:			${NAME}

clean:
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


run_vs_code: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE)

bin/$(EXECUTABLE): ${FILES} ${LIBFT_FILES}
					gcc ${FLAGS} -fsanitize=address -ggdb $^ -o $@ -lmlx -lXext -lX11 -lm

cleandebug:
					-rm ./bin/*

.PHONY:			all clean fclean re
