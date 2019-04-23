#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

// int					print_arg(t_spec *spec, va_list arg);

typedef struct		s_spec
{
	char			symb;
	int				width;
	int				space;
	int				sharp;
	int				plus;
	int				minus;
	int				zero;
	int				float_point;
	int				ll;
	int				l;
	int				hh;
	int				h;
}					t_spec;

#endif