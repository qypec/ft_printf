#include "header.h"

// // 'c' // 's' // // 'p'  string and char and point
void print_c(va_list arg)
{
	char symbol;

	symbol =(char) va_arg(arg, int);
	width (1, 0, 10);
	printWidth(1);
	addsymb_glbuffer(symbol);
	printWidthEnd();
} 

int *width_s(char *str, int index, int width)
{ 	
	int *p;

	if (!(p = (int *)malloc (sizeof(int) * 4)))
	    return (NULL);
	p[0] = 0; // do
	p[1] = 0; // posle
	p[2] = 0; // zero posle
	p[3] = 0; // size sembol
	while (str[width])
	    width++;
	if ( g_spec->minus == 1 &&  g_spec->width != 0)
	    if (( g_spec->width - width) > 0)
	        p[1] =  g_spec->width - width;
	if ( g_spec->plus == 1 || ( g_spec->width != 0 &&  g_spec->minus != 1))
	    if (( g_spec->width - width) > 0)
	        p[0] =  g_spec->width - width;
	    if ((( g_spec->width -  g_spec->precision) > 0) &&  g_spec->precision != 0)
	        p[0] =  g_spec->width -  g_spec->precision;
	if ( g_spec->precision > 0)
	    if (( g_spec->precision - width) > 0)
	        p[2] =  g_spec->precision - width;
	p[3] = width;
	return (p);
}
int printWidth_s(int *p)
{
    int index;

    index = 0;
    if (p[0] > 0)
    {
        while (index < p[0])
        {
            ft_putchar(' ');
            index++;
        }
    }
    return (index);
}

int print_s(va_list arg)
{
	char *str;
	int *p;
	char *ptr;
	int i;	

	str =(char *) va_arg(arg, void *);
	// width_s(str,  0, 0);
	// printWidth_s(p);
	update_glbuffer(str);
	// free(p);
	return (0);
}

int print_p(va_list arg)
{
	int size;
	int *p;
	long long int num;
	char *str;	
	size = 0;
	num = va_arg(arg, long long int);
	width(num,  0, 16);
	str = ft_itoa_base(num, 16);
	printWidth(num);
	update_glbuffer(str);
	printWidthEnd();
	size += ft_strlen(str) + 2;
	free(str);
	free(p);
	return (size);
}

void print_char(va_list arg)
{
	if ( g_spec->symb == 'c')
		print_c(arg);
	if ( g_spec->symb == 's')
		print_s(arg);
	if ( g_spec->symb == 'p')
		print_p(arg);
	return ;
}
