#include <unistd.h>

/**
 * Writes a char to the specified file descriptor
 *
 * @param	c	Character to write
 * @param	fd	File descriptor to write to
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
