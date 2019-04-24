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
 

 int print_o(t_spec *spec, va_list arg)
 {
    int         size;
    char        *str;
    int         num;
    int         *p;
    int         index;

    index = 0;
    num = va_arg(arg, int);
    str = ft_itoa_base(num, 8);
    p = width(num, spec, 0, 0);
    size = printWidth(p);
    ft_putstr(str);
    index = printWidthEnd(p);
    size = size + p[3] + index;
    free(str);
    free(p);
    return (size);
}

char *printX(char *str, t_spec *spec)
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
            str++;
        }
    return (str);
}

int print_x(t_spec *spec, va_list arg)
{
    int size;
    int num;
    char *str;
    int *p;
    int index;
    
    index = 0;
    num = va_arg(arg, int);
    str = ft_itoa_base(num, 16);
    p = width(num, spec, 0, 0);
    size = printWidth(p);
    str = printX(str, spec);
    ft_putstr(str);
    index = printWidthEnd(p);
    size = size + p[3] + index;
    free(str);
    free(p);
return (size);
}

int print_int(t_spec *spec, va_list arg)
{
    int size;

    size  = 0;
    if (spec->symb == 'd' || spec->symb == 'i' || spec->symb == 'u')
        size = print_di(spec, arg);
    if (spec->symb == 'o')
        size = print_o(spec, arg);
    if (spec->symb == 'x' || spec->symb == 'X')
        size = print_x(spec, arg);
    return (size);
}