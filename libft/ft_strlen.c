#include <wchar.h>

size_t	ft_strlen(const char *c)
{
	const char	*tmp;

	tmp = c;
	while (*tmp)
		tmp++;
	return (tmp - c);
}
