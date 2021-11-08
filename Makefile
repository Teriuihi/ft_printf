NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

MAIN=ft_printf.c
FUNCTIONS=printing.c hex.c hex_util.c
LIB_FT=ft_calloc.c ft_itoa.c ft_memset.c ft_putchar_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

FILES=$(addprefix functions/, $(FUNCTIONS)) $(MAIN)
FILES_OBJ=$(FILES:%.c=%.o) $(LIB_FT:%.c:%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(MAKE) -C libft/
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(FILES_OBJ)

clean:
	$(RM) $(FILES_OBJ)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re
