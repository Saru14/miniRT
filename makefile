# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/11 14:44:36 by jbodson           #+#    #+#              #
#    Updated: 2020/09/15 17:10:34 by jbodson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME	= main.c operator.c	

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= miniRT

CC	= gcc
RM	= rm -f

CFLAGS = -Wall -Wextra -Werror -I.

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C mlx
		${CC} -o ${NAME} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit
			
all: 		${NAME}

clean:
			make -C mlx clean
			${RM} ${OBJS} ${NAME}

fclean:		clean
			make -C mlx fclean
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all bonus
