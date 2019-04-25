#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <time.h>
# define TAB  "0123456789abcdef"

typedef struct		s_date
{
	int				year4;
	int				year2;
	int				weekday;
	int				month;
	int				day;
	// char			deldate;
	int				hour;
	int				min;
	int				sec;
	// char			deltime;

}					t_date;

}					t_date;

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
	int				k;
}					t_spec;

int					print_arg(t_spec *spec, va_list arg);
int					print_int(t_spec *spec, va_list arg);
int 				print_di (t_spec *spec, va_list arg);
int					print_d(int number, t_spec *spec);
int 				*width(long long number, t_spec *spec, long long int index, int width);
int					print_o(t_spec *spec, va_list arg);
int					printWidthEnd(int *p);
int					printWidth(int *p);
char				*ft_itoa_base(long long int value, int base);
int       			ft_itoa_help(long long int tmp, int base, int flag);
int					ft_abs(int nb);
//x - X
int					print_x(t_spec *spec, va_list arg);
char				*printX(char *str, t_spec *spec);
t_spec				struct_specifier(char *traverse, t_spec *spec);

 // 'c' // 's' // // 'p'  string and char and point 
 int				print_char(t_spec *spec, va_list arg);

int					is_cspdioux_bigx_fegbrk(char c);
int					is_lh_bigl(char c);
int					is_calculatesymb(char c);
int					*width_s(char *str,t_spec *spec, int index, int width);

// l and ll 
int 				print_dl(t_spec *spec, long int num);

t_spec				*read_lh_bigl(char *traverse, t_spec *spec);
t_spec				*read_calculatesymb(char с, t_spec *spec);
t_spec				*read_digit(char *traverse, t_spec *spec, const char *flag);

void				print_struct(t_spec	*spec);
#endif