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