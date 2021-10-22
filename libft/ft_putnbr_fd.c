#include <stdlib.h>
#include "../headers/libft.h"

void	ft_putnbr_fd(long n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	ft_putstr_fd(s, fd);
	free(s);
}
