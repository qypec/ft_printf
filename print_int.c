#include "header.h"

char *register_x(char *str)
{
	int index;	
	index = 0;
	if ( g_spec->symb == 'x')
		while (str[index])
		{
			if (str[index] >= 65 && str[index] <= 70)
				str[index] = str[index] + 32;
			index++;
		}
	if (g_spec->symb == 'X')
		while (str[index])
		{
			if (str[index] >= 97 && str[index] <= 122)
				str[index] = str[index] - 32;
			index++;
		}
	return (str);
}

void signX(long long int num)
{
	
	if (g_spec->symb == 'x' || g_spec->symb == 'X' || g_spec->symb == 'p')
	{
		if (g_spec->sharp == 1 && num > 0)
		{
			if (g_spec->symb == 'x')
				addstr_glbuffer("0x", 2);
			else if (g_spec->symb == 'X')
				addstr_glbuffer("0X", 2);
		}
		if (g_spec->symb == 'p')
			addstr_glbuffer("0x", 2);
	}
	else if (g_spec->symb =='o')
	{
		if (g_spec->sharp == 1 && (num != 0 || g_spec->precision == 0))
		{
			g_width->zero--;
			addsymb_glbuffer('0');
		}
	}
}

void sign(long long int num)
{
	if (g_spec->plus == 1 && num >= 0 && g_spec->symb != 'u')
	{
	    addsymb_glbuffer('+');
		g_width->space_left--;
		g_width->space_right--;
		if (g_spec->precision <= 0)
			g_width->zero--;
	}
	if (num < 0)
		addsymb_glbuffer('-');
	if (g_spec->symb == 'p')
		addstr_glbuffer("0x", 2);
	if (g_spec->symb =='o')
	{
		if (g_spec->sharp == 1 && (num != 0 || g_spec->precision == 0))
		{
			g_width->zero--;
			addsymb_glbuffer('0');
		}
	}
	if (g_spec->symb == 'x' || g_spec->symb == 'X')
		signX(num);
}

void display_int(long long int num, int base)
{
	char *str;
	long long int num1;

	num = reduction_signed(num);
	num1 = num;
	if (num < 0)
		num = -num;
	if (num == 0 && g_spec->precision >= 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base(num, base);
	width(num1, str);
	printWidth(num1);
	if (g_spec->precision >= 0 && num == 0)
	{
		printWidthEnd();
	}
	else
	{ 
		update_glbuffer(str);
		printWidthEnd();
	}
	free(str);
}

void  printWidthEnd()
{
	int index;

	index =0;
	if (g_width->space_right > 0)
	{
		while (index < g_width->space_right)
		{
			addsymb_glbuffer(' ');
			index++;
		}
	}
	return ;
}

int lenbase(unsigned long long int num, int base)
{
	int size;

	size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	if (size == 0)
		return (1);
return (size);
}


void assembl_int(va_list arg)
{
	long long int check;
	int base;

	base = 10;
	if (g_spec->symb == 'x' ||  g_spec->symb == 'X')
		base = 16;
	if (g_spec->symb == 'o')
		base = 8;
	if (g_spec->symb == 'u' || g_spec->symb == 'U' || g_spec->symb == 'o' || g_spec->symb == 'x' || g_spec->symb == 'X')
	{
		print_u(arg, base);
		return ;
	}
	if (g_spec->l == 1)
		check = va_arg(arg, long int);
	else if (g_spec->ll == 1)
		check = va_arg(arg, long long int);
	else if (g_spec->l == 0 &&  g_spec->ll == 0 && g_spec->j == 0 && g_spec->z == 0)
		check = va_arg(arg, int);
	else if (g_spec->z == 1)
		check = va_arg(arg, size_t);
	else if (g_spec->j == 1)
		check = va_arg(arg, size_t);
	display_int(check, base);
	return ;
}


static void width_three(long long num, char *str)
{
	if (g_spec->symb == 'o' && g_spec->precision <= 0)
		{
			g_width->space_left -= 1;
			g_width->space_right -= 1;
		}
		if (g_spec->symb == 'p' )
		{
			g_width->space_left -= 2;
			g_width->space_right -= 2;
		}
}

static void width_two(long long int num, char *str)
{
	if (g_spec->zero == 1 && g_spec->precision < 0) // 
	{
		g_width->zero = g_width->space_left;
		if (g_spec->sharp == 1 && (g_spec->symb == 'x' || g_spec->symb == 'X'))
			g_width->zero -= 2;
		g_width->space_left = 0;
	}
	if (g_spec->space == 1 && num >= 0 && g_spec->symb != 'u' 
	&& g_spec->symb != 'c' && g_spec->symb != 'U')
		if (g_width->space_left <= 0 )
			g_width->space_left =g_width->space_left * 0 + 1;
	if ((g_spec->sharp == 1 && g_spec->width > 0) || g_spec->symb == 'p')
	{
		if ((g_spec->symb == 'x' || g_spec->symb == 'X') && num > 0)
		{
			g_width->space_left -= 2;
			g_width->space_right -= 2;
		}
		if (g_spec->symb == 'o' && g_spec->precision <= 0)
		{
			g_width->space_left -= 1;
			g_width->space_right -= 1;
		}
		if (g_spec->symb == 'p' )
		{
			g_width->space_left -= 2;
			g_width->space_right -= 2;
		}
	}
}

void	width(long long int number, char *str)
{
	long long int num;
	
	num = number;
	g_width->width = ft_strlen(str);
	number = (g_spec->precision - g_width->width);
	if (num < 0 )
			g_width->width++;
	if (number < 0)
		number = 0;
	if (g_spec->width > g_width->width && g_spec->minus == 0)
	{	
		g_width->space_left =  g_spec->width - g_width->width;
	}
	else if (g_spec->minus == 1 && g_spec->width > g_spec->precision)
		g_width->space_right = g_spec->width - g_width->width;
			if (number != 0 && g_spec->symb != 's')
	{
		g_width->zero = number;
		g_width->space_left -=number;
		g_width->space_right -=number;
	}
	width_two(num, str);
	return ;
}

static void	printwidthtwo(long long int num)
{
	int index;

	index = 0;
	if (g_width->space_left > 0)
	{
		if (g_spec->plus == 1 && num >= 0) // fix num < 0 || 
			g_width->space_left = g_width->space_left - 1;
		while (index < g_width->space_left)
		{
			addsymb_glbuffer(' ');
			index++;
		}
		sign(num);
		return ;
	}
	if(g_spec->symb != 'x' && g_spec->symb != 'X' && g_spec->symb != 'p') //fix else
		sign(num);
	if (g_spec->symb == 'x' || g_spec->symb == 'X' || g_spec->symb == 'p')
		signX(num);
}

void	printWidth(long long int num)
{
	int index;
	
	if (g_spec->symb == 's' && g_width->width == 0)
	{
		g_width->space_left = g_spec->width;
		g_width->space_right = 0;
	}
	if (g_spec->symb == 'c' && g_width->width == 1)
	{
		if (g_spec->zero == 0 && g_spec->minus == 0)
		{
			g_width->zero = 0;
			g_width->space_left = g_spec->width - g_width->width;
		}
		else if (g_spec->zero == 0 && g_spec->minus == 1)
		{ 
			g_width->zero = 0;
			g_width->space_left = 0;
			g_width->space_right = g_spec->width - g_width->width;
		}
	}
	printwidthtwo(num);
	if (g_width->zero > 0)
	{
		index =0;
		while(g_width->zero > index)
		{
			addsymb_glbuffer('0');
			index++;
		}
	}
	return ;
}


