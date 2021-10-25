NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

MAIN=ft_printf.c
FUNCTIONS=printing_1.c hex.c hex_util.c

LIBS=libft/libft.a
FILES=$(addprefix functions/, $(FUNCTIONS)) $(MAIN)
FILES_OBJ=$(FILES:.c=.o)

all: $(NAME)

lib_ft:
	$(MAKE) -C libft/

$(NAME): $(FILES_OBJ) lib_ft
	ar -rcs $(NAME) $(FILES_OBJ) $(LIBS)

clean:
	$(RM) $(FILES_OBJ)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re lib_ft
