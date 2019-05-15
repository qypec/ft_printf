#include "header.h"
#include <limits.h>







void	rounding(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '9')\
			str[index] = '0';
		index++;
	}
}


void print_float(double num)
{
	unsigned long long			left;
	char						*str;
	int							size;
	double						x;

	if (g_spec->precision < 0)
		size  = CONST_WIDRTH_DOUBLE;
	else
		size = g_spec->precision;
	if (num < 0)
		x = -num;
	if (g_spec->precision > 0 || g_spec->sharp == 1)
		g_spec->width -= 1;
	g_spec->width -= size;
	left = (unsigned long long)x;
	str = ft_itoa_u(left);
	width(num, str);
	printWidth(num);
	update_glbuffer(str);
	if (g_spec->symb == 'f')
		if (g_spec->precision > 0 || g_spec->sharp == 1)
		{
			g_spec->width--;
			addsymb_glbuffer('.');
		}
	x -= left;
	while (size > 0)
	{
		addsymb_glbuffer((long long)(x * 10) + 0x30);
		x *= 10;
		x -=(long long)x;
		size--;	
	}
}


void assembl_float(va_list arg)
{
	double  num;

	if (g_spec->symb == 'f')
		num = va_arg(arg, double);
	if (g_spec->symb)
	print_float(num);
}