# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:17:57 by eholzer           #+#    #+#              #
#    Updated: 2022/11/16 15:41:21 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			d_specifier.c \
			u_specifier.c \
			p_specifier.c \
			x_specifier.c \
			other_specifiers.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

#.c.o: (the hidden rule)
#			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft
			cp libft/libft.a .
			mv libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}
			make -C libft clean

fclean:		clean
			rm -f ${NAME}
			rm -f libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re