# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:17:57 by eholzer           #+#    #+#              #
#    Updated: 2022/11/04 19:08:59 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

LIBC	= ar rc

LIBR	= ranlib

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:
			cd libft && make re bonus

${NAME}:	${OBJS} libft
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re