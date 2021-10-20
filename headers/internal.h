#ifndef INTERNAL_H
# define INTERNAL_H
int		print_string(char *s);
int		print_char(int c);
int		print_int(int i);
int		print_long(long i);
int		print_str_free(char *s);
char	*get_hex_upper(long nbr);
char	*get_hex_lower(long nbr);
char	*get_pointer(unsigned long nbr);
#endif
