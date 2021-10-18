#include "../headers/libft.h"

int	print_string(char *s)
{
	ft_putstr_fd(s, 1);
	return (0);
}

int	print_char(int c)
{
	ft_putchar_fd((char)c, 1);
	return (0);
}

int	print_int(int i)
{
	ft_putnbr_fd(i, 1);
	return (0);
}