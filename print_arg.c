 #include "header.h"

// 'd' // 'i' // 'o' // 'u' // 'X' // 'x' int 

// f // e // 'g'  float

// 'c' // 's' // // 'p'  string and char and point  
 
// 'к'     
// 'k'   
// '%'  
// 'b'

void            width_processing(char *str)
{
	int	size;
	int	width;	
	width = 0;
	size = ft_strlen(str);
	if ( g_spec->width - size >= 0)
		width =  g_spec->width - size;
	if ( g_spec->minus == 1)
		addstr_glbuffer(str, size);
	if ( g_spec->zero == 1)
	{
		while (width--)
			addsymb_glbuffer('0');
	}
	else
	{
		while (width--)
			addsymb_glbuffer(' ');
	}
	if ( g_spec->minus != 1)
		addstr_glbuffer(str, size);
}
void print_float(double num)
{
	long long int	left;
	char		*str;
	int		a;
	int		size;


	size  = 6;
	if (g_spec->precision > 0)
		size = g_spec->precision;
	else
		size = CONST_WIDRTH_DOUBLE;
	left =(long long int)num;
	str = ft_itoa_base(left, 10);
	update_glbuffer(str);
	addsymb_glbuffer('.');
	num -= left;
	int index = 0;
	while (num > 0 && index < size)
	{
		num = num * 10;
		a =(int)num;
		num = num - a;
		str = ft_itoa_base(a, 10);
		update_glbuffer(str);
		index++;
	}
}


void assembl_float(va_list arg)
{
	double  num;

	if (g_spec->symb == 'f')
		num = va_arg(arg, double);
	print_float(num);
}

int		print_arg(char *traverse, va_list arg)
{
	if ( g_spec->symb == 'k')
		print_date(traverse, arg);
	if ( g_spec->symb == '%')
		width_processing("%");
	if ( g_spec->symb == 'd' ||  g_spec->symb == 'i' ||  g_spec->symb == 'o' ||  g_spec->symb == 'u' ||  g_spec->symb == 'x' ||  g_spec->symb == 'X' || g_spec->symb == 'U')
		assembl_int(arg);
	if ( g_spec->symb == 'c' ||  g_spec->symb == 's' ||  g_spec->symb == 'p')
		print_char(arg);
	 if ( g_spec->symb == 'f' || g_spec->symb == 'e' ||  g_spec->symb == 'g')
		assembl_float(arg);
	return (0);
}
