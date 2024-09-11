NAME = libftprintf.a

FILES = ft_printf.c\
ft_putchar.c\
ft_decnosig.c\
ft_decsig.c\
ft_hexadec.c\
ft_ptr.c\
ft_prtstring.c

OBJECTS = $(FILES:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

%.o:	%.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS) $(NAME)

re: all

.PHONY: re all clean fclean