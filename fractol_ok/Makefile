# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 08:19:14 by gcosenza          #+#    #+#              #
#    Updated: 2024/03/01 08:28:33 by gcosenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
SRCS = events.c init.c main.c math_utils.c render.c string_utils.c utils.c
OBJS = $(SRCS:.c=.o)
MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext
all: $(MLX_DIR) $(NAME)
$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure
$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) $(FLAGS) -o $(NAME) -g
bonus: $(MLX_DIR)
	cc -Wall -Wextra -Werror  $(FLAGS) -o $(NAME)
clean:
	rm -f $(OBJS) 
fclean: clean
	rm -f $(NAME) -d -R $(MLX_DIR)
re: fclean all
