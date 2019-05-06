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
    if ( g_spec->symb == 'X')
        while (str[index])
        {
            if (str[index] >= 97 && str[index] <= 122)
                str[index] = str[index] - 32;
            index++;
        }
    return (str);
}

void display_int(long long int num, int base)
{
    int *p;
    char *str;

    num = reduction_signed(num);
    p = width(num, 0, base);
    printWidth(p, num);
    str = ft_itoa_base(num, base);
    if ( g_spec->symb == 'X' ||  g_spec->symb == 'x')
        str = register_x(str);
    if ( g_spec->plus == 1 && num >= 0)
    {
        ft_putchar('+');
		// len++
    }
    ft_putstr(str);
    printWidthEnd(p);
    ft_strlen(str);
    free(p);
    free(str);
}

int printWidthEnd(int *p)
{
	return (1);
}

int		*width_u(unsigned long long number, unsigned long long int index, int width)
{
	int *p;
	p = malloc(sizeof(int) * 4);
	p[0] = p[1] = p[2] = p[3] = 0;
	return (p);
}



void assembly_int(va_list arg)
{
	long long int check;
	long long int a;
	int base;

	base = 10;
	if ( g_spec->symb == 'x' ||  g_spec->symb == 'X')
		base = 16;
	if ( g_spec->symb == 'o')
		base = 8;
	if ( g_spec->symb == 'u')
	{
		print_u(arg, base);
		return ;
	}
	if ( g_spec->l == 1)
		check = va_arg(arg, long int);
	if ( g_spec->ll == 1)
		check = va_arg(arg, long long int);
	if ( g_spec->l == 0 &&  g_spec->ll == 0)
		check = va_arg(arg, int);
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
return (size);
}


int *width(long long number, unsigned long int index,  int base)
{
	int width;

	width = 0;
	// 0x and 0X and 0 
	// # 
	if (number < 0)
		index = -number;
	else
		index = number;
	width = lenbase(index, base);
	if ( g_spec->width > width ||  g_spec->minus == 0)
		g_width->width_left =  g_spec->width - width;
	
	return (0);
}


int printWidth(int *p, long long int num)
{
	
    return (0);
}



