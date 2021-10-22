#include <stdlib.h>

char	*ft_memset(void *b, int c, size_t len);

static int	int_len(long nb)
{
	int	len;

	len = 0;
	while (nb > 9 || nb < -9)
	{
		len++;
		nb /= 10;
	}
	return (len + 1);
}

static void	fill(char *a, long n, int len)
{
	int	tmp;

	while (len)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp *= -1;
		*(a + len - 1) = (char)(tmp + '0');
		n /= 10;
		len--;
	}
}

char	*ft_itoa(long n)
{
	char	*a;
	int		len;
	int		negative;

	negative = 0;
	if (n < 0)
		negative = 1;
	len = int_len(n);
	a = malloc((negative + len + 1) * sizeof(char));
	if (a == 0)
		return (0);
	ft_memset(a, 0, negative + len + 1);
	if (negative)
	{
		*a = '-';
		fill(a + 1, n, len);
	}
	else
		fill(a, n, len);
	return (a);
}
