NAME = libft.a

SCR = ft_strchr.c ft_strcmp.c get_next_line.c get_next_line_utils.c ft_memmove.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_split.c ft_strlcpy.c

OBJ = $(SCR:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

re: clean all

fclean: clean
	@rm -f $(NAME)

