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

int *width_s(char *str,t_spec *spec, int index, int width)
{  
    int *p;
    
    if (!(p = (int *)malloc (sizeof(int) * 3)))
        return (NULL);
    p[0] = 0; // do
    p[1] = 0; // posle
    p[2] = 0; // zero posle
    p[3] = 0; // size sembol
    while (str[width])
    {
        width++;
    }
    if (spec->minus == 1 && spec->width != 0)
        if ((spec->width - width) > 0)
            p[1] = spec->width - width;
    if (spec->plus == 1 || (spec->width != 0 && spec->minus != 1))
        if ((spec->width - width) > 0)
            p[0] = spec->width - width;
    if (spec->precision > 0)
        if ((spec->precision - width) > 0)
            p[2] = spec->precision - width;
    p[3] = width;
    return (p);
}
int printWidth_s(int *p)
{
    int index;

    index = 0;
    if (p[0] > 0)
    {
        while (index < p[0])
        {
            ft_putchar(' ');
            index++;
        }
    }
    return (index);
}

int print_s(t_spec *spec, va_list arg)
{
    int size;
    char *str;
    int *p;
    char *ptr;
    int i;

    size = 0;
    str =(char *) va_arg(arg, void *);
    p = width_s(str, spec, 0, 0);
    size = printWidth_s(p);
    if (spec->precision > 0)
    {
        ptr = ft_strncpy(ft_strnew(spec->precision), str, spec->precision);
        ft_putstr(ptr);
        free(ptr);
        size +=spec->precision;
    }
    else 
        ft_putstr(str);
        size += p[3];
    free(str);
    return (size);
}

int print_char(t_spec *spec, va_list arg)
{
    int size;

    size = 0;
    if (spec->symb == 'c')
        size = print_c(spec, arg);
    if (spec->symb == 's')
        size = print_s(spec, arg);
    if (spec->symb == 'p')
    ;
    return (size);
}