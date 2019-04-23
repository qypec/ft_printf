#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

// int					print_arg(t_spec *spec, va_list arg);

typedef struct		s_spec
{
	char			symb;
	int				space;
	char			*typeflag;
}					t_spec;

#endif