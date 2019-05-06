#include "header.h"

// 'd' // 'i' // decimal 

// 'u' unsigned decimal

// 'o' unsigned octal

 // 'X' // 'x' unsigned  hexadecimal
 


static char *register_x(char *str)
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

void sign(long long int num)
{
	if (g_spec->plus == 1 && num >= 0)
	{
	    addsymb_glbuffer('+');
		g_width->space_left--;
		g_width->space_right--;
		if (g_spec->precision <= 0)
			g_width->zero--;
	}
	if (num < 0)
	{
		addsymb_glbuffer('-');
		g_width->space_left--;
		g_width->space_right--;
		if (g_spec->precision <= 0)
			g_width->zero--;
	}
}

void signX(long long int num)
{
	
	if (g_spec->symb == 'x' || g_spec->symb == 'X')
	{
		if (g_spec->sharp == 1 && num > 0)
		{
			if (g_spec->symb == 'x')
				addstr_glbuffer("0x", 2);
			else if (g_spec->symb == 'X')
				addstr_glbuffer("0X", 2);
		}
	}
	else if (g_spec->symb =='o')
	{
		if (g_spec->sharp == 1)
		{
			addsymb_glbuffer('0');
		}
	}
}
void display_int(long long int num, int base)
{
	char *str;


	num = reduction_signed(num);
	width(num, 0, base);
	printWidth(num);
	if (num < 0)
		num = -num;
	//if (num == 0)
	//	addsymb_glbuffer('0');

	str = ft_itoa_base(num, base);
	if ( g_spec->symb == 'X' ||  g_spec->symb == 'x')
	    str = register_x(str);
	update_glbuffer(str);
	printWidthEnd();
	free(str);
}

void  printWidthEnd()
{
	int index;
	char *str;

	index =0;
	// if (g_spec->width > g_spec->precision && g_spec->minus == 1)
	// 	g_width->space_right = g_spec->width - g_spec->precision;
	if (g_width->space_right > 0)
	{
		str = malloc(sizeof(char) * g_width->space_right + 1);
		while (index < g_width->space_right)
		{
			str[index] = ' ';
			index++;
		}
		str[index] = '\0';
		addstr_glbuffer(str, index);
		free(str);
	}
	return ;
}

int		*width_u(unsigned long long number, unsigned long long int index, int width)
{
	int *p;
	p = malloc(sizeof(int) * 4);
	p[0] = p[1] = p[2] = p[3] = 0;
	return (p);
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
	if (g_spec->symb == 'u')
	{
		print_u(arg, base);
		return ;
	}
	if (g_spec->l == 1)
		check = va_arg(arg, long int);
	if (g_spec->ll == 1)
		check = va_arg(arg, long long int);
	if (g_spec->l == 0 &&  g_spec->ll == 0 && g_spec->j == 0)
		check = va_arg(arg, int);
	if (g_spec->j == 1)
		check = va_arg(arg, uintmax_t);
	display_int(check, base);
	return ;
}

int lenbase(unsigned long long int num, int base)
{
	int size;

	size = 0;
	while (num > 0)
	{
		num /= base;
		size++;
	}
	if (size == 0)
		return (1);
return (size);
}


void	width(long long number, unsigned long int index,  int base)
{
	if (number < 0)
		index = -number;
	else
		index = number;
	g_width->width = lenbase(index, base);
	number = (g_spec->precision - g_width->width); // precision
	if (number < 0)
		number = 0;
	if (g_spec->width > g_width->width && g_spec->minus == 0)
		g_width->space_left =  g_spec->width - g_width->width;
	else if (g_spec->minus == 1 && g_spec->width > g_spec->precision)
		g_width->space_right = g_spec->width - g_width->width;
	if (number != 0 && g_spec->precision > 0)
	{
		g_width->zero = number;
		g_width->space_left -=number;
		g_width->space_right -=number;
	}
	if (g_spec->zero == 1 && number == 0)
	{
		g_width->zero = g_width->space_left;
		g_width->space_left = 0;
	}
	if (g_spec->space == 1 && g_spec->width == 0 && g_spec->precision == 0)
		g_width->space_left++;
	// 6
	if (g_spec->sharp == 1)
	{
		if (g_spec->symb == 'x' || g_spec->symb == 'X')
		{
			g_width->space_left -= 2;
			g_width->zero -= 2;
			g_width->space_right -= 2;
		}
		if (g_spec->symb == 'o')
		{
			g_width->space_left -= 1;
			g_width->zero -= 1;
			g_width->space_right -= 1;
		}

	}
	return ;
}

static void	printwidthtwo(long long int num)
{
	int index;

	index = 0;
	if (g_width->space_left > 0)
	{
		if (num < 0 || g_spec->plus == 1)
			g_width->space_left = g_width->space_left - 1;
		while (index < g_width->space_left)
		{
			addsymb_glbuffer(' ');
			index++;
		}
		sign(num);
	}
	else if(g_spec->symb != 'x' && g_spec->symb != 'X')
		sign(num);
	if (g_spec->symb == 'x' || g_spec->symb == 'X')
		signX(num);
	if (g_spec->symb =='o')
		signX(num);
}

void	printWidth(long long int num)
{
	int index;
	
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



