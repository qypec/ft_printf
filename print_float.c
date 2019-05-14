#include "header.h"

void print_float(double num)
{
	double	left;
	char			*str;
	int				a;
	int				size;


	size  = 6;
	if (g_spec->precision > 0)
		size = g_spec->precision;
	else
		size = CONST_WIDRTH_DOUBLE;
	left =(long long int)num;
	if (left < 0)
	left = -left;
	str = ft_itoa_base(left, 10);
	update_glbuffer(str);
	addsymb_glbuffer('.');
	if (num < 0)
		num = -num;
	num -= left;
	int index = 0;
	while (num > 0 && index < size)
	{
		num = num * 10;
		a =(int)num;
		num = num - a;
		str = ft_itoa_base(a, 10);
		update_glbuffer(str);
		index++;
	}
}


void assembl_float(va_list arg)
{
	double  num;

	if (g_spec->symb == 'f')
		num = va_arg(arg, double);
	print_float(num);
}