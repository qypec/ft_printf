#include "header.h"

// // 'c' // 's' // // 'p'  string and char and point
int print_c(t_spec *spec, va_list arg)
{
    int size;
    int *p;
    char symbol;

    symbol =(char) va_arg(arg, int);
    p = width (1, spec, 0, 0);
    size = printWidth(p);
    ft_putchar(symbol);
    size += printWidthEnd(p) + p[3];



    return (size);
} 

int print_char(t_spec *spec, va_list arg)
{
    int size;

    size = 0;
    if (spec->symb == 'c')
        size = print_c(spec, arg);
    if (spec->symb == 's')
    ;
    if (spec->symb == 'p')
    ;
    return (size);
}