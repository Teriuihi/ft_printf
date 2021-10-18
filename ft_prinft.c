#include "headers/libft.h"
#include <stdarg.h>
#include "headers/internal.h"

/** todo rename
 * TODO ft_putchar_fd should return error code
 * Prints argument (converted)
 * @param str
 * @param ap
 * @return
 */
int	func_call(const char *str, va_list ap)
{
	int err;

	err = 0;
	if (*str == 0)
		return(-2);
	if (*str == 's')
		err = print_string(va_arg(ap, char *));
	else if (*str == 'c')
		err = print_char(va_arg(ap, int));
	else if (*str == 'i')
		err = print_int(va_arg(ap, int));
	else
		ft_putchar_fd(*str, 1);
	return (err);
}

int	ft_printf(char *str, ...)
{
	va_list ap;
	int	err;

	err = 0;
	va_start(ap, str);
	while (*str && !err)
	{
		if (*str == '%')
		{
			err = func_call((str + 1), ap);
			if (err == -2)
				str++;
			else if (!err)
				str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
	return (err);
}