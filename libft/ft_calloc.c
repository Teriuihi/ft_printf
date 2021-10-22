#include <stdlib.h>
#include <wchar.h>
#include "../headers/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*loc;

	loc = malloc(size * count);
	if (loc == 0)
		return (0);
	ft_memset(loc, 0, size * count);
	return (loc);
}
