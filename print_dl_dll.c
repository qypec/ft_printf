#include "header.h"

long long int reduction_signed(t_spec *spec, long long int num)
{
    if (spec->l)
        num = (long int)num;
    if (spec->l == 0 && spec->ll == 0)
        num = (int)num;
    if (spec->h == 1)
        num = (short)(num);
    if (spec->hh == 1)
        num = (char)num;
    if (num < 0)
        if (spec->symb == 'x' || spec->symb == 'X')
            num += 4294967296;
    return (num);
}

unsigned long long reduction_unsigned(t_spec *spec, unsigned long long int num)
{
    if (spec->l == 1)
        num = (unsigned long int)num;
    if (spec->ll == 0 && spec-> ll == 0)
        num = (unsigned int)num;
    if (spec->h == 1)
        num = (unsigned short)num;
    if (spec->hh == 1)
        num = (unsigned char)num;
    return (num);
}



int		ft_numblen_u(unsigned long long int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_u(unsigned long long int n)
{
	long long int		len;
	char	*str;
	unsigned long long int		i;

	len = ft_numblen_u(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = len - 1;
	str[len] = '\0';
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	return (str);
}

int display_u(t_spec *spec, unsigned long long int num, int base)
{
    int size;
    int *p;
    char *str;

    p = NULL;
    size = 0;
    p = width_u(num, spec, 0, 0);
    num = reduction_unsigned(spec, num);
    size = printWidth(p, spec, num);
    str = ft_itoa_u(num);
    ft_putstr(str);
    size += printWidthEnd(p);
    size += ft_strlen(str);
    free(p);
    free(str);
    return (size);
}
int print_u(t_spec *spec, va_list arg, int base)
{
    int size;
    unsigned long long int num;

    size = 0;
    if (spec->ll == 1)
        num = va_arg(arg, unsigned long long int);
    if (spec->l == 1)
        num = va_arg(arg, unsigned long);
    if (spec->ll == 0 && spec->l == 0)
        num = va_arg(arg, unsigned int);
    size = display_u(spec, num, base);
    return (size);
}