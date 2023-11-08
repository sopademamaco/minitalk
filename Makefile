# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:33:06 by davioliv          #+#    #+#              #
#    Updated: 2023/11/08 16:43:16 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_OBJ = ${CLIENT_SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIB = ft_printf/libftprintf.a
LIBDIR = ft_printf

all:	${NAME}

$(NAME):	${SERVER_OBJ} ${CLIENT_OBJ}
	make -C ${LIBDIR} all
	cp ${LIB} ${NAME}
	ar rcs ${NAME} ${SERVER_OBJ} ${CLIENT_OBJ}
	${CC} ${CFLAGS} ${SERVER_OBJ} ${NAME} -o server
	${CC} ${CFLAGS} ${CLIENT_OBJ} ${NAME} -o client

clean:
	make -C ${LIBDIR} clean
	${RM} ${SERVER_OBJ} ${CLIENT_OBJ} server client

fclean:	clean
	make -C ${LIBDIR} fclean
	${RM} ${NAME}

re:	all fclean

.PHONY: all clean fclean re
