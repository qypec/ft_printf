#include "header.h"

// // 'c' // 's' // // 'p'  string and char and point
int print_c(va_list arg)
{
    int size;
    int *p;
    char symbol;

    symbol =(char) va_arg(arg, int);
    width (1, 0, 10);
    size = printWidth(p, 0);
    ft_putchar(symbol);
    size += printWidthEnd(p) + p[3];


    free (p);
    return (size);
} 

int *width_s(char *str, int index, int width)
{  
    int *p;
    
    if (!(p = (int *)malloc (sizeof(int) * 4)))
        return (NULL);
    p[0] = 0; // do
    p[1] = 0; // posle
    p[2] = 0; // zero posle
    p[3] = 0; // size sembol
    while (str[width])
        width++;
    if ( g_spec->minus == 1 &&  g_spec->width != 0)
        if (( g_spec->width - width) > 0)
            p[1] =  g_spec->width - width;
    if ( g_spec->plus == 1 || ( g_spec->width != 0 &&  g_spec->minus != 1))
        if (( g_spec->width - width) > 0)
            p[0] =  g_spec->width - width;
        if ((( g_spec->width -  g_spec->precision) > 0) &&  g_spec->precision != 0)
            p[0] =  g_spec->width -  g_spec->precision;
    if ( g_spec->precision > 0)
        if (( g_spec->precision - width) > 0)
            p[2] =  g_spec->precision - width;
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

int print_s(va_list arg)
{
    int size;
    char *str;
    int *p;
    char *ptr;
    int i;

    size = 0;
    str =(char *) va_arg(arg, void *);
    p = width_s(str,  0, 0);
    size = printWidth_s(p);
    if ( g_spec->precision > 0)
    {
        ptr = ft_strncpy(ft_strnew( g_spec->precision), str,  g_spec->precision);
        ft_putstr(ptr);
        free(ptr);
        if (p[3] > 0)
            size += g_spec->precision;
    }
    else 
    {
        ft_putstr(str);
        size += p[3];
    }
    free(p);
    return (size);
}

int print_p(va_list arg)
{
    int size;
    int *p;
    long long int num;
    char *str;

    size = 0;
    num = va_arg(arg, long long int);
    width(num,  0, 16);
    str = ft_itoa_base(num, 16);
    size = printWidth(p,  0);
    ft_putstr(str);
    size +=printWidthEnd(p);
    size += ft_strlen(str) + 2;
    free(str);
    free(p);
    return (size);
}

int print_char(va_list arg)
{
    int size;

    size = 0;
    if ( g_spec->symb == 'c')
        size = print_c( arg);
    if ( g_spec->symb == 's')
        size = print_s( arg);
    if ( g_spec->symb == 'p')
        size = print_p( arg);
    return (size);
}
