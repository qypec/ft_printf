#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <time.h>
# define TAB  "0123456789abcdef"
# define RESERVE 15

typedef struct		s_width
{
	int				width_left;
	int				width_right;
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
	int				hh;
	int				h;
}					t_spec;

// global 
struct s_width		*g_width;
struct s_output		*g_output;
struct s_spec		*g_spec;
// end global

/* reduction */

long long int		reduction_signed(long long int num);
unsigned long long	reduction_unsigned(unsigned long long int num);
int					*width(long long number, unsigned long int index, int base);
int					print_u(va_list arg, int base);
int					*width_u(unsigned long long number, unsigned long long int index, int width);
int					ft_printf(const char *format, ...);
int					print_arg(char *traverse, va_list arg);
void				print_int(va_list arg);
int					print_d(int number);
int					print_u(va_list arg, int base);
int					printWidthEnd(int *p);
int					printWidth(int *p, long long int num);
char				*ft_itoa_base(long long int value, int base);
int					ft_itoa_help(long long int tmp, int base, int flag);
int					ft_abs(int nb);
int					isplay_u(unsigned long long int num);
void				display_int(long long int num, int base);
void				assembly_int(va_list arg);

//x - X
char				*printX(char *str);
void				struct_specifier(char *traverse);

 // 'c' // 's' // // 'p'  string and char and point 
int					print_char(va_list arg);
int					is_cspdioux_bigx_fegbrk(char c);
int					is_lh_bigl(char c);
int					is_calculatesymb(char c);
int					*width_u(unsigned long long number, unsigned long long int index, int width);
int					*width_s(char *str, int index, int width);

// l and ll 
int					print_dl(long int num);

void				read_lh_bigl(char *traverse);
void				read_calculatesymb(char c);
void				read_digit(char *traverse, const char *flag);
void				parse_precision(char *traverse);
void				parse_width(char *traverse);
void				parse_calculatesymb(char *traverse);
void				parse_space(char *traverse);
void				parse_lh_bigl(char *traverse);

void				print_date(char *traverse, va_list arg);
void				bust_printf(int errorcode);
void				init_bufferoutput(void);
void				is_it_buffer_overflow(size_t size);
void				add_memory(size_t size);
void				free_bufferoutput(void);
void				addsymb_glbuffer(char c);
void				update_glbuffer(char *str);
void				addstr_glbuffer(char *str, size_t size);


#endif
