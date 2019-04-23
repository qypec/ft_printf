#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

 

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

int					print_arg(t_spec *spec, va_list arg);
int					print_int(t_spec *spec, va_list arg);
int 					print_di (t_spec *spec, va_list arg);
int					print_d(int number, t_spec *spec);
int					*width(int number, t_spec *spec, int index, int width);

#endif