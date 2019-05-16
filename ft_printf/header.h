#ifndef HEADER_H
# define HEADER_H

# include "../speedtest/speedtest.h"
# include <stdio.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <time.h>

# define PRECISION	1
# define WIDTH		2

# define TAB  "0123456789abcdef"
# define null "(null)"
# define RESERVE 15
# define CONST_WIDRTH_DOUBLE 6
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"
# define COLOR_SIZE 5

struct s_width		*Width;

typedef struct		s_width
{
	int				space_left;
	int				zero;
	int				space_right;
	int				width;
}					t_widt;

typedef struct		s_output
{
	char 			*str;
	size_t			size;
	int				overflow_counter;
	int				error;
	int				buffsize;
}					t_output;


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
	int				j;
	int				hh;
	int				h;
	int				z;
}					t_spec;

// global 
struct s_width		*g_width;
struct s_output		*g_output;
struct s_spec		*g_spec;
// end global

/* reduction */

long long int		reduction_signed(long long int num);
unsigned long long	reduction_unsigned(unsigned long long int num);
void				width(long long number, char *str);
int					*width_u(unsigned long long number, unsigned long long int index, int width);
int					ft_printf(const char *format, ...);
int					print_arg(char *traverse, va_list arg);
void				print_int(va_list arg);
int					print_d(int number);
void				print_u(va_list arg, int base);
void				printWidthEnd();
void				printWidth(long long int num);
char				*ft_itoa_base(long long int value, int base);
int					ft_itoa_help(long long int tmp, int base, int flag);
int					ft_abs(int nb);
int					isplay_u(unsigned long long int num);
void				display_int(long long int num, int base);
void				assembl_int(va_list arg);

//x - X
char				*printX(char *str);
void				struct_specifier(char *traverse);
char 				*struct_spec(char *traverse);

 // 'c' // 's' // // 'p'  string and char and point 
void				print_char(va_list arg);
int					is_cspdioux_bigx_fegbrk(char c);
int					is_lh_bigl(char c);
int					is_calculatesymb(char c);
int					*width_u(unsigned long long number, unsigned long long int index, int width);
char				*ft_itoa_u(unsigned long long int n);
// l and ll 
int					print_dl(long int num);

void				read_calculatesymb(char c);
void				read_digit(char *traverse, const int flag);
int					read_width_or_precision(char *traverse, int i, int flag);
int					move_after_digits(char *traverse);
int					read_spaces(char *traverse, int i);

char 				*parse_spaces(char *traverse);
char				*parse_digit(char *traverse, const int flag);
char				*parse_width_or_precision(char *traverse, int flag);
char				*parse_calculatesymb(char *traverse);
char				*parse_lh_bigl(char *traverse);
char				*whichsymb(char *traverse);

int					read_lh_bigl(char *traverse, int i);

void				print_date(char *traverse, va_list arg);
void				bust_printf(int errorcode);
void				init_bufferoutput(void);
void				is_it_buffer_overflow(size_t size);
void				add_memory(size_t size);
void				free_bufferoutput(void);
void				addsymb_glbuffer(char c);
void				update_glbuffer(char *str);
void				addstr_glbuffer(char *str, size_t size);

void				print_float(double num);
void				assembl_float(va_list arg);

char				*take_color(char *traverse);

int					ft_printf(const char *format, ...);

#endif