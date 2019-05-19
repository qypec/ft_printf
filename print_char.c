#include "header.h"

// // 'c' // 's' // // 'p'  string and char and point
void print_c(va_list arg)
{
	char symbol;

	symbol =(char) va_arg(arg, int);
	if (symbol == 0)
	{
		width (1, " ");
		printWidth(1);
		// printWidthEnd();
		addsymb_glbuffer(symbol);
	}
	else
		{
			width (1, " ");
			printWidth(1);
			addsymb_glbuffer(symbol);
			printWidthEnd();
		}
} 

int print_s(va_list arg, char *str, char *ptr, char *point)
{
	int index; 
	
	index = 0;
	str = (char *) va_arg(arg, void *);
	if (str == NULL)
	{
		str = ft_strcpy(ft_strnew(6), null);
		point = str;
	}
	if (g_spec->precision >= 0 && g_spec->precision < ft_strlen(str))
	{
		ptr = ft_strnew(g_spec->precision);
		while (index != g_spec->precision)
			ptr[index++] = ' ';
		ptr[g_spec->precision] = '\0';
		ptr = ft_strncpy(ptr, str, g_spec->precision);
		str = ptr;
	}
	width(1, str);
	printWidth(1);
	update_glbuffer(str);
	printWidthEnd();
	ft_memdel((void *)&ptr);
	ft_memdel((void *)&point);
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
		print_s(arg, NULL, NULL, NULL);
	if ( g_spec->symb == 'p')
		print_p(arg);
	return ;
}
