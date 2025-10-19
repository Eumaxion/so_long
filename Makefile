# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 17:11:36 by mlima-si          #+#    #+#              #
#    Updated: 2025/10/20 00:04:18 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

SCR = ./src/so_long.c\
./src/check_map.c\
./src/read_map.c\
./src/exit_game.c\
./src/gather_elements.c\
./src/handle_key.c\
./src/start_game.c\
./src/check_path.c\
./src/errors.c\

BONUS_SCR = ./src_bonus/so_long_bonus.c\
./src_bonus/check_map_bonus.c\
./src_bonus/read_map_bonus.c\
./src_bonus/exit_game_bonus.c\
./src_bonus/gather_elements_bonus.c\
./src_bonus/handle_key_bonus.c\
./src_bonus/start_game_bonus.c\
./src_bonus/check_path_bonus.c\
./src_bonus/errors_bonus.c\

OBJ = $(SCR:.c=.o)

BONUS_OBJS = $(BONUS_SCR:.c=.o)

CFLAGS += -Wall -Werror -Wextra

LIBFT = ./libraries/libft/libft.a

FT_PRINTF = ./libraries/libft/ft_printf/libftprintf.a

#MLX_LIB = ./libraries/minilibx-linux

FLAGS += -L ./libraries/minilibx-linux -lmlx -lXext -lX11 -Lminilibx-linux

GREEN  := \033[0;32m
RED    := \033[0;31m
YELLOW := \033[1;33m
RESET  := \033[0m

all:  $(NAME)
#all: $(MLX_LIB) $(NAME)
$(NAME): $(OBJ)
	@cd ./libraries/libft && make
	@cd ./libraries/libft/ft_printf && make
	@cd ./libraries/minilibx-linux && make
	@cc $(OBJ) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(FLAGS) -o $(NAME)
	@echo "$(GREEN)\n COMPILED $(RESET)\n"

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@cd ./libraries/libft && make
	@cd ./libraries/libft/ft_printf && make
	@cd ./libraries/minilibx-linux && make
	@cc $(BONUS_OBJS) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(FLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)\n BONUS COMPILED $(RESET)\n"

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)
	@make -C ./libraries/libft clean
	@make -C ./libraries/libft/ft_printf clean
	@make -C ./libraries/minilibx-linux clean
	@echo "$(YELLOW) OBJECTS REMOVED $(RESET)"

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C ./libraries/libft fclean
	@make -C ./libraries/libft/ft_printf fclean
	@echo "$(RED) EXECUTABLE REMOVED $(RESET)"

#$(MLX_LIB):
#	@wget https://cdn.intra.42.fr/document/document/38621/minilibx-linux.tgz
#	@tar -xzf minilibx-linux.tgz
#	@rm minilibx-linux.tgz
#	@echo "\n------------- DOWNLOADED -------------\n"

re: clean all

.PHONY: all clean fclean re
