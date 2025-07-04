# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 17:11:36 by mlima-si          #+#    #+#              #
#    Updated: 2025/07/04 18:30:15 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SCR = so_long.c check_map.c read_map.c exit_game.c gather_elements.c handle_key.c start_game.c check_path.c errors.c

OBJ = $(SCR:.c=.o)

CFLAGS += -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

FLAGS += -lmlx -lXext -lX11 -Lminilibx-linux

all: $(NAME)

$(NAME):$(OBJ)
	@cd libft && make
	@cd minilibx-linux && make
	@cc $(OBJ)  $(CFLAGS) $(LIBFT) $(FLAGS) -o $(NAME)
	@echo "\n------------- COMPILATION DONE -------------\n"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@make -C minilibx-linux clean
	@echo "\n------------- REMOVED OBJECTS -------------\n"

fclean: clean
	@rm -f $(NAME) $(OBJ)
	@make -C libft fclean
	@rm -rf ./minilibx-linux
	@echo "\n------------- REMOVED	 EXECUTABLES -------------\n"

re: clean all

download:
	@wget https://cdn.intra.42.fr/document/document/36126/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz
	@echo "\n------------- DOWNLOADED -------------\n"
.PHONY: all clean fclean re
