#ifndef LIBFT_H
# define LIBFT_H
# include <wchar.h>
size_t	ft_strlen(const char *c);
char	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
char	*ft_itoa(long n);
void	ft_bzero(void *s, size_t n);
#endif
