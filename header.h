#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>
# define TAB  "0123456789abcdef"

typedef struct		s_spec
{
	char			symb;
	int				width;
	int				space;
	int				sharp;
	int				plus;
	int				minus;
	int				zero;
	int				precision;
	int				big_l;
	int				ll;
	int				l;
	int				hh;
	int				h;
}					t_spec;
/* reduction */
long long int 		reduction_signed(t_spec *spec, long long int num);
unsigned long long 	reduction_unsigned(t_spec *spec, unsigned long long int num);
int 				*width(long long number, t_spec *spec, unsigned long int index, int width, int base);

int					print_arg(t_spec *spec, va_list arg);
int					print_int(t_spec *spec, va_list arg);
int 				assembly_int(t_spec *spec, va_list arg, int base);
int					print_d(int number, t_spec *spec);
int					print_u(t_spec *spec, va_list arg, int base);

int					printWidthEnd(int *p);
int 				printWidth(int *p, t_spec *spec);
char				*ft_itoa_base(long long int value, int base);
int       			ft_itoa_help(long long int tmp, int base, int flag);
int					ft_abs(int nb);
int					isplay_u(t_spec *spec, unsigned long long int num);
int 				display_int(t_spec *spec, long long int num, int base);
char				*register_x(char *str, t_spec *spec);
//x - X
char				*printX(char *str, t_spec *spec);
t_spec				struct_specifier(char *traverse, t_spec *spec);

 // 'c' // 's' // // 'p'  string and char and point 
 int				print_char(t_spec *spec, va_list arg);

int					is_cspdioux_bigx_fegbrk(char c);
int					is_lh_bigl(char c);
int					is_calculatesymb(char c);
int					*width_s(char *str,t_spec *spec, int index, int width);
int					*width_u(unsigned long long number, t_spec *spec, unsigned long long int index, int width);

// l and ll 
int 				print_dl(t_spec *spec, long int num);

t_spec				*read_lh_bigl(char *traverse, t_spec *spec);
t_spec				*read_calculatesymb(char с, t_spec *spec);
t_spec				*read_digit(char *traverse, t_spec *spec, const char *flag);

void				print_struct(t_spec	*spec);
#endif