#include <wchar.h>

char	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = b;
	while (len > 0)
	{
		len--;
		*tmp = c;
		tmp++;
	}
	return (b);
}
