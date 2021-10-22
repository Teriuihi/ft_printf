NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

MAIN=ft_printf.c
FUNCTIONS=printing_1.c
LIB_FT=ft_bzero.c ft_calloc.c ft_itoa.c ft_memset.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c

FILES=$(addprefix functions/, $(FUNCTIONS)) $(addprefix Libft/, $(LIB_FT)) $(MAIN)
FILES_OBJ=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ) functions/libft.a

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
