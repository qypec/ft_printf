 #include "header.h"

// 'd' // 'i' // 'o' // 'u' // 'X' // 'x' int ++

// f // e // 'g'  float

// 'c' // 's' // // 'p'  string and char and point  
 
// 'к'     
// 'k'   
// '%'  
// 'b' 

int		print_percent(t_spec *spec)
{
	int num;

	num = 0;
	while (num < spec->width - 1)
	{
		ft_putchar(' ');
		num++;
	}
	ft_putchar('%');
	return (num + 1);
}

int     print_arg(t_spec *spec, va_list arg)
{
    int size;
     
    size = 0;
    if (spec->symb == '%')
    	size = print_percent(spec);
    if (spec->symb == 'd' || spec->symb == 'i' || spec->symb == 'o' || spec->symb == 'u' || spec->symb == 'x' || spec->symb == 'X')
        size = print_int(spec, arg);
    if (spec->symb == 'c' || spec->symb == 's' || spec->symb == 'p')
        size = print_char(spec, arg);
          // if (spec->symb == 'f' || spec->symb == 'e' || spec->symb == 'g')
    //     size = print_float(spec, arg);
    
    return (size);   
}