#include <stdlib.h>
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

int	print_long(long i)
{
	ft_putnbr_fd(i, 1);
	return (0);
}

int	print_str_free(char *s)
{
	int	err;

	if (!s)
		return (-1);
	err = print_string(s);
	free(s);
	return (err);
}
