#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	fetching_csp(char *step, va_list arg);

#endif