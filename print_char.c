#include "header.h"

// // 'c' // 's' // // 'p'  string and char and point
void print_c(va_list arg)
{
	char symbol;

	symbol =(char) va_arg(arg, int);
	width (1, " ");
	printWidth(1);
	// if (symbol == 0)
	// 	printWidthEnd();
	// else
	// 	{
			addsymb_glbuffer(symbol);
			printWidthEnd();
		// }
} 

int print_s(va_list arg)
{
	char *str;
	char *ptr;
	int i;	

	ptr = NULL;
	str = (char *) va_arg(arg, void *);
	if (str == NULL)
		str = ft_strcpy(ft_strnew(6), null);
	if (g_spec->precision > 0)
	{
		ptr = ft_strncpy(ft_strnew(g_spec->precision), str, g_spec->precision);
		str = ptr;
	}
	width(1, str);
	printWidth(1);
	update_glbuffer(str);
	printWidthEnd();
	if (ptr != NULL)
		free(ptr);
	return (0);
}

void print_p(va_list arg)
{
	long long int num;
	char *str;

	num = va_arg(arg, long long int);
	if (num < 0)
		num = -num;
	str = ft_itoa_base(num, 16);
	width(num, str);
	printWidth(num);
	update_glbuffer(str);
	printWidthEnd();
	free(str);
	return ;
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
