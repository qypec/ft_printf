 #include "header.h"

// 'd' // 'i' // 'o' // 'u' // 'X' // 'x' int ++

// f // e // 'g'  float

// 'c' // 's' // // 'p'  string and char and point  
 
// 'к'     
// 'k'   
// '%'  
// 'b'    

int print_interest(t_spec *spec, va_list arg)
{
    int *p;
    int size;

    size = 0;
    p = width(1, spec, 0, 0, 10);
    size = printWidth(p, spec);
    ft_putchar('%');
    size = size +  1 + printWidthEnd(p);
    free(p);
    return (size);
}



int     print_arg(t_spec *spec, va_list arg)
{
    int size;

    size = 0;
    if (spec->symb == 'd' || spec->symb == 'i' || spec->symb == 'o' || spec->symb == 'u' || spec->symb == 'x' || spec->symb == 'X')
        size = print_int(spec, arg);
    if (spec->symb == 'c' || spec->symb == 's' || spec->symb == 'p')
        size = print_char(spec, arg);
    if (spec->symb == '%')
        size = print_interest(spec, arg);
          // if (spec->symb == 'f' || spec->symb == 'e' || spec->symb == 'g')
    //     size = print_float(spec, arg);
    
    return (size);   
}