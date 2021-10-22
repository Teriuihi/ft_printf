#include "../headers/libft.h"

static int	recursion(char *res, long nbr,
				char *characters, int size)
{
	int	pos;
	int	base;

	base = ft_strlen(characters);
	if (!nbr)
		return (size);
	pos = size;
	size = recursion(res, nbr / base, characters, size + 1);
	res[size - pos - 1] = characters[nbr % base];
	return (size);
}

static int	recursion_ul(char *res, unsigned long nbr,
				char *characters, int size)
{
	int	pos;
	int	base;

	base = ft_strlen(characters);
	if (!nbr)
		return (size);
	pos = size;
	size = recursion_ul(res, nbr / base, characters, size + 1);
	res[size - pos - 1] = characters[nbr % base];
	return (size);
}

//TODO move to library
static char	*get_base_str(char *prefix)
{
	char	*res;
	char	*tmp;
	int		pref_len;

	if (prefix)
		pref_len = ft_strlen(prefix);
	else
		pref_len = 0;
	res = ft_calloc(pref_len + 8 + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_bzero(res, pref_len + 8 + 1);
	tmp = res;
	while (prefix && *prefix)
	{
		*tmp = *prefix;
		tmp++;
		prefix++;
	}
	return (res);
}

/** TODO move to library
 * Converts any base 10 number to any other base
 * @param nbr Number to convert
 * @param characters Characters that make up the base
 * 	(this is assumed to be a valid base)
 * @param prefix Prefix for the result (can be NULL)
 * @param max_len length of prefix + longest the resulting hex could be
 * @return a malloced string with the number in a new base
 */
char	*ft_get_base(long nbr, char *characters, char *prefix)
{
	char	*res;
	char	*tmp;

	res = get_base_str(prefix);
	if (!res)
		return (NULL);
	tmp = res;
	while (*tmp)
		tmp++;
	recursion(tmp, nbr, characters, 0);
	return (res);
}

char	*ft_get_base_ul(unsigned long nbr, char *characters, char *prefix)
{
	char	*res;
	char	*tmp;

	res = get_base_str(prefix);
	if (!res)
		return (NULL);
	tmp = res;
	while (*tmp)
		tmp++;
	recursion_ul(tmp, nbr, characters, 0);
	return (res);
}

char	*get_hex_lower(long nbr)
{
	return (ft_get_base(nbr, "0123456789abcdef", 0));
}

char	*get_hex_upper(long nbr)
{
	return (ft_get_base(nbr, "0123456789ABCDEF", 0));
}

char	*get_pointer(unsigned long nbr)
{
	return (ft_get_base_ul(nbr, "0123456789abcdef", "0x"));
}
