 #include "header.h"

// 'd' // 'i' // 'o' // 'u' // 'X' // 'x' int 

// f // e // 'g'  float

// 'c' // 's' // // 'p'  string and char and point  
 
// 'к'     
// 'k'   
// '%'  
// 'b' 

void  print_percent(t_spec *spec)
{
    int *p;
    
    width(1, spec, 0, 10);
    size_len = printWidth(p, spec, 0);
    ft_putchar('%');
    size_len = size_len +  1 + printWidthEnd(p);
    free(p);
}

int     print_arg(char *traverse, t_spec *spec, va_list arg)
{

    if (spec->symb == 'q')
        size_len = print_matrix(traverse, arg);
    // if (spec->symb == 'k')
    // 	size = print_date(traverse, arg);
    if (spec->symb == '%')
        print_percent(spec);
    if (spec->symb == 'd' || spec->symb == 'i' || spec->symb == 'o' || spec->symb == 'u' || spec->symb == 'x' || spec->symb == 'X')
        assembly_int(spec, arg);
    if (spec->symb == 'c' || spec->symb == 's' || spec->symb == 'p')
        size_len = print_char(spec, arg);
          // if (spec->symb == 'f' || spec->symb == 'e' || spec->symb == 'g')
    //     size = print_float(spec, arg);
    
    return (size_len);   
}
