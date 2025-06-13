NAME = libft.a

SCR = ft_strchr.c ft_strcmp.c

OBJ = $(SCR:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

re: clean all

fclean: clean
	@rm -f $(NAME)

