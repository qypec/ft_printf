#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
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
	int				big_l;
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

t_spec				struct_specifier(char *traverse, t_spec *spec);

int					is_cspdioux_bigx_fegbrk(char c);
int					is_lh_bigl(char c);
int					is_calculatesymb(char c);

t_spec				*read_lh_bigl(char *traverse, t_spec *spec);
t_spec				*read_calculatesymb(char с, t_spec *spec);
t_spec				*read_digit(char *traverse, t_spec *spec);

void				print_struct(t_spec	*spec);
#endif