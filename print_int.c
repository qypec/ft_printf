#include "header.h"

// 'd' // 'i' // decimal 

// 'u' unsigned decimal

// 'o' unsigned octal

 // 'X' // 'x' unsigned  hexadecimal
 


static char *register_x(char *str, t_spec *spec)
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

void display_int(t_spec *spec, long long int num, int base)
{
    int *p;
    char *str;

    num = reduction_signed(spec, num);
    p = width(num, spec, 0, base);
    printWidth(p, spec, num);
    str = ft_itoa_base(num, base);
    if (spec->symb == 'X' || spec->symb == 'x')
        str = register_x(str, spec);
    if (spec->plus == 1 && num >= 0)
    {
        ft_putchar('+');
        size_len++;
    }
    ft_putstr(str);
    printWidthEnd(p);
    ft_strlen(str);
    free(p);
    free(str);
}

void assembly_int(t_spec *spec, va_list arg)
{
    long long int check;
    long long int a;
    int base;

    base = 10;
    if (spec->symb == 'x' || spec->symb == 'X')
        base = 16;
    if (spec->symb == 'o')
        base = 8;
    if (spec->symb == 'u')
    {
        print_u(spec, arg, base);
        return ;
    }
    if (spec->l == 1)
        check = va_arg(arg, long int);
    if (spec->ll == 1)
        check = va_arg(arg, long long int);
    if (spec->l == 0 && spec->ll == 0)
        check = va_arg(arg, int);
    display_int(spec, check, base);
    return ;
}




int *width(long long number, t_spec *spec, unsigned long int index,  int base)
{


   return (0);
}



int printWidth(int *p, t_spec *spec, long long int num)
{
    return (0);
}



