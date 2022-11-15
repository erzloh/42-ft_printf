# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:17:57 by eholzer           #+#    #+#              #
#    Updated: 2022/11/15 11:00:07 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra# -Ilibft

#.c.o: (the hidden rule)
#			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C Libft
			cp libft/libft.a .
			mv libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}
			make -C Libft clean

fclean:		clean
			rm -f ${NAME}
			rm -f Libft/libft.a

re:			fclean all

test:		${OBJS}
			make -C Libft
			gcc ${CFLAGS} main.c ${OBJS} Libft/libft.a
#			gcc ${CFLAGS} main.c ${OBJS} -L. -lft (is the same as above)

tclean:		fclean
			rm -f a.out

.PHONY:		all clean fclean re test ftest