#include "../headers/libft.h"

/**
 * Set's all bytes to 0 in a given byte array
 *
 * @param	s	Array to set to 0
 * @param	n	Amount of bytes to set to 0
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
