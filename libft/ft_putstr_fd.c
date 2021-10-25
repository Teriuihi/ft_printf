#include <unistd.h>
#include "../headers/libft.h"

/**
 * Writes a string to the specified file descriptor
 *
 * @param	s	String to write
 * @param	fd	File descriptor to write to
 */
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
