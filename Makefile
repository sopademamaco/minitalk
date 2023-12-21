# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:33:06 by davioliv          #+#    #+#              #
#    Updated: 2023/12/21 10:15:57 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
SERVER_SRC = srcs/server.c
CLIENT_SRC = srcs/client.c
SERVER_BONUS_SRC = bonus/server_bonus.c
CLIENT_BONUS_SRC = bonus/client_bonus.c
SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_OBJ = ${CLIENT_SRC:.c=.o}
SERVER_BONUS_OBJ = ${SERVER_BONUS_SRC:.c=.o}
CLIENT_BONUS_OBJ = ${CLIENT_BONUS_SRC:.c=.o}

CC = cc -Wall -Werror -Wextra
RM = rm -f
LIB = srcs/ft_printf/libftprintf.a
LIBDIR = srcs/ft_printf

all:	${NAME}

$(NAME):	${SERVER_OBJ} ${CLIENT_OBJ}
	make -C ${LIBDIR} all
	cp ${LIB} ${NAME}
	ar rcs ${NAME} ${SERVER_OBJ} ${CLIENT_OBJ}
	${CC} ${SERVER_OBJ} ${NAME} -o server
	${CC} ${CLIENT_OBJ} ${NAME} -o client

clean:
	make -C ${LIBDIR} clean
	${RM} ${SERVER_BONUS_OBJ} ${CLIENT_BONUS_OBJ} ${SERVER_OBJ} ${CLIENT_OBJ} server client server_bonus client_bonus

fclean:	clean
	make -C ${LIBDIR} fclean
	${RM} ${NAME}

re:	fclean all

bonus:	${SERVER_BONUS_OBJ} ${CLIENT_BONUS_OBJ}
	make -C ${LIBDIR} all
	cp ${LIB} ${NAME}
	ar rcs ${NAME} ${SERVER_BONUS_OBJ} ${CLIENT_BONUS_OBJ}
	${CC} ${SERVER_BONUS_OBJ} ${NAME} -o server_bonus
	${CC} ${CLIENT_BONUS_OBJ} ${NAME} -o client_bonus

.PHONY: all clean fclean re bonus
