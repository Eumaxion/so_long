# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 17:11:36 by mlima-si          #+#    #+#              #
#    Updated: 2025/07/02 14:32:20 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.out

SCR = so_long.c check_map.c read_map.c exit_game.c gather_elements.c render_map.c handle_key.c start_game.c check_path.c errors.c

OBJ = $(SCR:.c=.o)

FLAGS += -lmlx -lXext -lX11 -Lminilibx-linux

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ)
	@cd libft && make
	@cd minilibx-linux && make
	@cc $(OBJ)  $(CFLAGS) ./libft/libft.a  $(FLAGS) -o $(NAME)

clean:
	@rm -f $(NAME) $(OBJ)
	@make -C libft fclean
	@make -C minilibx-linux clean
re: clean all

.PHONY: all clean re
