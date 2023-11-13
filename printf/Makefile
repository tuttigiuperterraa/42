# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 18:43:55 by gcosenza          #+#    #+#              #
#    Updated: 2023/11/13 19:56:27 by gcosenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
SRCS_MANDATORY = ft_checktype_pf.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c ft_putpointer.c ft_putstr.c ft_putunsigned.c
OBJS_MANDATORY = ${SRCS_MANDATORY:.c=.o}
HEADER = printf.h

all: ${NAME}

${NAME}: ${OBJS_MANDATORY}
	ar rc ${NAME} ${OBJS_MANDATORY}	
	ranlib ${NAME}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f ${OBJS_MANDATORY}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
