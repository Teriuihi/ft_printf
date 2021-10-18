NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FUNCTIONS=printing_1.c
FILES=$(addprefix functions/, $(FUNCTIONS)) ft_printf.c
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
