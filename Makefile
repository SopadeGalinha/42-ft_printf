# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 16:15:29 by jhgoncal          #+#    #+#              #
#    Updated: 2022/03/28 16:35:46 by jhgoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

SRCS = ${wildcard f*.c}
OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= /bin/rm -f
CFLAGS	= -Wall -Wextra -Werror -I ${INC}

INC	= ./
CL = ar -rc
RL = ar -s

${NAME}:	${OBJS}
	${CL}	${NAME}	${OBJS}
	${RL}	${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM}	${NAME}

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: clean fclean all re