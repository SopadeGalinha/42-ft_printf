# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 13:36:34 by jhogonca          #+#    #+#              #
#    Updated: 2023/05/30 23:07:14 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME =  libftprintf.a

SRCS = ft_printf.c
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
	printf "Compiling the program..\033[0;32m [OK]\033[0m\n"

all: ${NAME}
	printf "Program is ready to use \033[0;32m[OK]\033[0m\n"

clean:
	${RM} ${OBJS}
	printf "Removing object files..\033[0;32m [OK]\033[0m\n"

fclean:	clean
	${RM}	${NAME}
	printf "Removing executable....\033[0;32m [OK]\033[0m\n"

re: fclean all

norm:
	printf "\033[0;32mRunning Norminette\n\n\033[0m"
	printf "\033[0;35mInclude\n\033[0m"
	norminette -R CheckDefine *.h
	printf "\033[0;36m\nFunctions\n\033[0m"
	norminette -R CheckForbiddenSourceHeader *.c
	printf "\n"
	
.PHONY: clean fclean all re