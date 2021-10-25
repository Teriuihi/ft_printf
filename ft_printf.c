#include "headers/libft.h"
#include "headers/internal.h"
#include <stdarg.h>

int	handle_character_2(const char *str, va_list ap, int err)
{
	if (*str == 'x')
		err = print_str_free(get_hex_lower(va_arg(ap, long)));
	else if (*str == 'X')
		err = print_str_free(get_hex_upper(va_arg(ap, long)));
	else if (*str == 'p')
		err = print_str_free(get_pointer(va_arg(ap, unsigned long)));
	else if (*str == '%')
		ft_putchar_fd(*str, 1);
	else
	{
		ft_putchar_fd(*str, 1);
		ft_putchar_fd(*(str - 1), 1);
	}
	return (err);
}

/**
 * TODO ft_putchar_fd should return error code
 * Prints argument (converted)
 * @param str
 * @param ap
 * @return
 */
int	handle_character(const char *str, va_list ap)
{
	int	err;

	err = 0;
	if (*str == 0)
		return (-2);
	if (*str == 's')
		err = print_string(va_arg(ap, char *));
	else if (*str == 'c')
		err = print_char(va_arg(ap, int));
	else if (*str == 'i')
		err = print_int(va_arg(ap, int));
	else if (*str == 'd')
		err = print_long(va_arg(ap, long));
	else if (*str == 'u')
		err = print_long(va_arg(ap, unsigned long));
	else
		return (handle_character_2(str, ap, err));
	return (err);
}

/**
 * Print a string to the standard output along with any specified arguments
 * 	at specified locations
 * @param	str	The string to print
 * @param	...	Any arguments that are requested to be printed
 * @return
 */
int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		err;

	err = 0;
	va_start(ap, str);
	while (*str && !err)
	{
		if (*str == '%')
		{
			err = handle_character((str + 1), ap);
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
