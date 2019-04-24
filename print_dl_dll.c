#include "header.h"



int print_dl(t_spec *spec, long int num)
{
    int size;
    int *p;
    char *str;
    
    size = 0;
    p = width(num, spec, 0, 0);
    size = printWidth(p);
    str = ft_itoa(num);
    ft_putstr(str);
    size += printWidthEnd(p);
    size += ft_strlen(str);
    free(p);
    free(str);
    return (size);
}

int print_dll(t_spec *spec, long long num)
{
    int size;
    int *p;
    char *str;
    
    size = 0;
    p = width(num, spec, 0, 0);
    size = printWidth(p);
    str = ft_itoa(num);
    ft_putstr(str);
    size += printWidthEnd(p);
    size += ft_strlen(str);
    free(p);
    free(str);
    return (size);
}