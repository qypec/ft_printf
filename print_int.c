#include "header.h"

// 'd' // 'i' // decimal 

// 'u' unsigned decimal

// 'o' unsigned octal

 // 'X' // 'x' unsigned  hexadecimal
 


int printWidthEnd(int *p)
{
    int index; 

    index = 0;
    if (p[1] > 0)
        while (index < p[1])
        {
            ft_putchar(' ');
            index++;
        }
    return (index);
}
 


char *register_x(char *str, t_spec *spec)
{
    int index;

    index = 0;
    if (spec->symb == 'x')
        while (str[index])
        {
            if (str[index] >= 65 && str[index] <= 70)
                str[index] = str[index] + 32;
            index++;
        }
    if (spec->symb == 'X')
        while (str[index])
        {
            if (str[index] >= 97 && str[index] <= 122)
                str[index] = str[index] - 32;
            index++;
        }
    return (str);
}


int print_int(t_spec *spec, va_list arg)
{
    int size;
    int base;

    base = 10;
    if (spec->symb == 'X' || spec->symb == 'x')
        base = 16;
    if (spec->symb == 'o')
        base = 8;
    size = assembly_int(spec, arg, base);
    return (size);
}

int *width(long long number, t_spec *spec, unsigned long int index, int width, int base)
 {
    int *p;
    if (number < 0)
        index = -number;
    else 
        index = number;
    if (!(p = (int *)malloc (sizeof(int) * 4)))
        return (NULL);
    p[0] = p[1] = p[2] = p[3] = 0; 
    while (index > 0)
    {
        index = index / base;
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

int *width_u(unsigned long long number, t_spec *spec, unsigned long long int index, int width)
 {
    int *p;
    
    index = number;
    if (!(p = (int *)malloc (sizeof(int) * 4)))
        return (NULL);
    p[0] = p[1] = p[2] = p[3] = 0; 
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

int printWidth(int *p, t_spec *spec)
{
    int index;
    if (spec->symb == 'p')
            ft_putstr("0x");

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



int assembly_int(t_spec *spec, va_list arg, int base)
{
    int size;
    long long int check;

    size = 0;
    if (spec->symb == 'u')
    {
        size = print_u(spec, arg, base);
        return (size);
    }
    if (spec->l)
        check = va_arg(arg, long int);
    if (spec->ll)
        check = va_arg(arg, long long int);
    if (spec->l == 0 && spec->ll == 0)
        check = va_arg(arg, int);
    if (spec->symb == 'x' || spec->symb == 'X')
        check = -check; 
    size = display_int(spec, check, base);
    return (size);
 }