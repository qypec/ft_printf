#include "header.h"

int *width(int number, t_spec *spec, int index, int width)
 {
    int *p;
    
    index = number;
    if (!(p = (int *)malloc (sizeof(int) * 3)))
        return (NULL);
    p[0] = 0; // do
    p[1] = 0; // posle
    p[2] = 0; // zero posle
    p[3] = 0; // size sembol
    while (index > 0)
    {
        index = index / 10;
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

int printWidth(int *p)
{
    int index;

    index = 0;
    if (p[0] > 0 && p[2] == 0)
    {
        while (index < p[0])
        {
            ft_putchar(' ');
            index++;
        }
    }
    else
        while (index < p[2])
        {
            ft_putchar('0');
            index++;
        }
    return (index);
}

 int print_d(int number, t_spec *spec)
 {
    int *p;
    int index;
    int size;

    index = 0;
    p = width(number, spec, 0, 0);
    index  = printWidth(p);
    size = index;
    ft_putnbr(number);
    index = printWidthEnd(p);
    size += index + p[3];
    free(p);
    return (size);
}

 int print_di (t_spec *spec, va_list arg)
 {
     int number;
     int size;

     size = 0;

     if (spec->symb == 'd' || spec->symb == 'i' || (spec->symb == 'u'))
     {
        number = va_arg(arg, int);
        size = print_d(number, spec);
     }
     return (size);
 }