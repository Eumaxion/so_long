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

SOURCES = main.c utils.c

FLAGS += -lmlx -lXext -lX11 -Lminilibx-linux

RM += rm -f

all: $(NAME)

$(NAME):
	@cc $(SOURCES) $(FLAGS) -o $(NAME)

clean:
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean re