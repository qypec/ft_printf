#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <time.h>
# define TAB  "0123456789abcdef"
# define RESERVE 15

long int				size_len;
struct s_width				*Width;

typedef struct				s_width
{
	int				width_left;
	int				width_right;
}					t_widt;

typedef struct				 s_name
{
	char 				*str;
	int				size_len;
	int				error;
	struct s_name 	*next;
} t_name;

typedef struct		s_date
{
	int				year4;
	int				year2;
	int				weekday;
	int				month;
	int				day;
	int				hour;
	int				min;
	int				sec;
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
}					t_spec;
/* reduction */

long long int		reduction_signed(t_spec *spec, long long int num);
unsigned long long	reduction_unsigned(t_spec *spec, unsigned long long int num);
int			*width(long long number, t_spec *spec, unsigned long int index, int base);
int			print_u(t_spec *spec, va_list arg, int base);
int			*width_u(unsigned long long number, t_spec *spec, unsigned long long int index, int width);
int			ft_printf(const char *format, ...);
int			print_arg(char *traverse, t_spec *spec, va_list arg);
void			print_int(t_spec *spec, va_list arg);
int			print_d(int number, t_spec *spec);
int			print_u(t_spec *spec, va_list arg, int base);
int			printWidthEnd(int *p);
int			printWidth(int *p, t_spec *spec, long long int num);
char			*ft_itoa_base(long long int value, int base);
int			ft_itoa_help(long long int tmp, int base, int flag);
int			ft_abs(int nb);
int			isplay_u(t_spec *spec, unsigned long long int num);
void			display_int(t_spec *spec, long long int num, int base);
void			assembly_int(t_spec *spec, va_list arg);

//x - X
char			*printX(char *str, t_spec *spec);
t_spec			struct_specifier(char *traverse, t_spec *spec);

 // 'c' // 's' // // 'p'  string and char and point 
int			print_char(t_spec *spec, va_list arg);
int			is_cspdioux_bigx_fegbrk(char c);
int			is_lh_bigl(char c);
int			is_calculatesymb(char c);
int			*width_s(char *str,t_spec *spec, int index, int width);
int			*width_u(unsigned long long number, t_spec *spec, unsigned long long int index, int width);

// l and ll 
int			print_dl(t_spec *spec, long int num);

t_spec			*read_lh_bigl(char *traverse, t_spec *spec);
t_spec			*read_calculatesymb(char c, t_spec *spec);
t_spec			*read_digit(char *traverse, t_spec *spec, const char *flag);

t_spec			*parse_precision(char *traverse, t_spec *spec);
t_spec			*parse_width(char *traverse, t_spec *spec);
t_spec			*parse_calculatesymb(char *traverse, t_spec *spec);
t_spec			*parse_space(char *traverse, t_spec *spec);
t_spec			*parse_lh_bigl(char *traverse, t_spec *spec);

int					print_date(char *traverse, va_list arg);
void				bust_printf(int errorcode);

int					print_matrix(char *traverse, va_list arg);

#endif
