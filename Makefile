# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 17:11:36 by mlima-si          #+#    #+#              #
#    Updated: 2025/06/11 13:52:43 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.out

SCR = main.c

OBJ = $(SCR:.c=.o)

FLAGS += -lmlx -lXext -lX11 -Lminilibx-linux

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ)
	@cd Libft && make
	@cc $(OBJ)  $(CFLAGS) ./Libft/libft.a -o $(NAME)

clean:
	@rm -f $(NAME) $(OBJ)
	@make -C Libft fclean

re: clean all

.PHONY: all clean re