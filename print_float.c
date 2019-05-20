#include "header.h"
#include <limits.h>

void	width_double(long double num, char *str)
{
	if (g_spec->precision  > 0 || g_spec->sharp == 1)
		g_spec->width--;
	if (num < 0 || (g_spec->plus == 1 && num > 0))
		g_spec->width--;
	if (g_spec->width > (ft_strlen(str) + g_spec->precision) && g_spec->minus == 0)
		g_width->space_left = g_spec->width -  (ft_strlen(str) + g_spec->precision);
	else if (g_spec->width > (ft_strlen(str) + g_spec->precision) && g_spec->minus == 1)
		g_width->space_right = g_spec->width -  (ft_strlen(str) + g_spec->precision);
	if (g_spec->space == 1 && g_spec->width == 0 && g_spec->precision < 0)
		g_width->space_left++;
	if (g_spec->zero == 1)
	{
		g_width->zero = g_width->space_left;
		g_width->space_left = 0;
	}
}

void	printWidthEnd_double(long double num)
{
	if (g_width->space_right > 0)
	{
		while (g_width->space_right > 0)
		{
			addsymb_glbuffer(' ');
			g_width->space_right--;
		}
	}
}
void	printWidth_double(long double num, char *str)
{
	if (g_width->space_left > 0)
	{
		while (g_width->space_left > 0)
		{
			addsymb_glbuffer(' ');
			g_width->space_left--;
		}
	}
	else if (g_width->zero > 0)
	{
		if (num < 0)
			addsymb_glbuffer('-');
		else if (g_spec->plus == 1 && num > 0)
		{
			addsymb_glbuffer('+');
			g_spec->plus = 0;
		}	
		while (g_width->zero > 0)
		{
			addsymb_glbuffer('0');
			g_width->zero--;
		}
	}
	if (g_spec->precision > 0 || g_spec->sharp == 1)
	{
		if (g_width->zero == 0 && num < 0)
			addsymb_glbuffer('-');
		else if (g_spec->plus == 1 && num > 0)
			addsymb_glbuffer('+');
		update_glbuffer(str);
		addsymb_glbuffer('.');
	}
	else
	{
		if (g_spec->zero == 0 && num < 0)
			addsymb_glbuffer('-');
		else if (g_spec->plus == 1 && num > 0)
			addsymb_glbuffer('+');
		update_glbuffer(str);
		addsymb_glbuffer('.');

	}
}
void print_float(long double num)
{
	unsigned long long			left;
	char						*str;
	int							size;
	long double					x;

	if (g_spec->precision < 0)
		size  = CONST_WIDRTH_DOUBLE;
	else
		size = g_spec->precision;
	if (num < 0)
		x = -num;
	else 
		x = num;
	left = (unsigned long long)x;
	str = ft_itoa_u(left);
	width_double(num, str);
	printWidth_double(num, str);
	x -= left;
	while (size > 0)
	{
		addsymb_glbuffer((long long)(x * 10) + 0x30);
		x *= 10;
		x -=(long long)x;
		size--;	
	}
	if ((long long)(x * 10) >= 5)
		g_output->str[g_output->size - 1] = g_output->str[g_output->size - 1] + 1;
	printWidthEnd_double(num);
	free(str);
	str = NULL;
}


void assembl_float(va_list arg)
{
	 long double  num;

	if (g_spec->symb == 'f' && g_spec->big_l == 0)
		num = va_arg(arg, double);
	else if (g_spec->big_l == 1)
		num = va_arg(arg, long double);
	print_float(num);
}