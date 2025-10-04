NAME = libftprintf.a

SOURCES = ft_printf.c	ft_putchar.c	ft_putstr.c		ft_putnmb.c		ft_unsignmb.c	ft_puthexa.c	ft_putpointer.c\

FLAGS += -Wall -Werror -Wextra

RM += rm -f

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

.c.o:
	@cc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
