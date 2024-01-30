# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 13:36:34 by jhogonca          #+#    #+#              #
#    Updated: 2024/01/30 19:46:20 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME =  libftprintf.a

SRCS = ft_printf.c print_functions_diux.c print_functions_csp.c utils.c
OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= /bin/rm -f
CFLAGS	= -I ${INC}

INC	= ./
CL = ar -rc
RL = ar -s

${NAME}:	${OBJS}
	${CL}	${NAME}	${OBJS}
	${RL}	${NAME}
	printf "Compiling the program..\033[0;32m [OK]\033[0m\n"

all: ${NAME}

bonus:	${NAME}

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
