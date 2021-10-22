#include <unistd.h>
#include <wchar.h>

size_t	ft_strlen(char *c);

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
