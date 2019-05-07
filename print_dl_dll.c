#include "header.h"
#include <limits.h>

long long int	reduction_signed(long long int num)
{
	unsigned long long int z;
	if ( g_spec->l)
		num = (long int)num;
	else if ( g_spec->l == 0 &&  g_spec->ll == 0 && g_spec->h == 0 && g_spec->hh == 0 && g_spec->j == 0 && g_spec->z == 0)
		num = (int)num;
	else if ( g_spec->h == 1)
		num = (short)(num);
	else if (g_spec->hh == 1)
		num = (char)num;
	else if (g_spec->j == 1)
	{
		if (num <= -4294967296)
			z = num - (unsigned long long int)1844674407370955161; 
	
		return (num);
	}
	if (num < 0)
	{
			if (g_spec->symb == 'x' ||  g_spec->symb == 'X')
				num += 4294967296;
	}
	return (num);
}

unsigned long long reduction_unsigned(unsigned long long int num)
{
	if ( g_spec->l == 1)
		num = (unsigned long int)num;
	if ( g_spec->ll == 0 &&  g_spec-> l == 0 && g_spec->j == 0 && g_spec->h == 0 && g_spec->hh == 0)
		num = (unsigned int)num;
	if ( g_spec->h == 1)
		num = (unsigned short)num;
	if ( g_spec->hh == 1)
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
		str[i] = (n % 10) + 48;
		i--;
		n /= 10;
	}
	return (str);
}

int display_u(unsigned long long int num, int base)
{
	char *str;
	
	reduction_unsigned(num);
	str = ft_itoa_u(num);
	width(num, str);
	printWidth(num);
	update_glbuffer(str);
	printWidthEnd();
	free(str);
	return (0);
}

void  print_u(va_list arg, int base)
{
	unsigned long long int num;

	if ( g_spec->ll == 1)
	    num = va_arg(arg, unsigned long long int);
	else if (g_spec->l == 1 || g_spec->symb == 'U')
	    num = va_arg(arg, unsigned long);
	else if (g_spec->j == 1)
		num = va_arg(arg, size_t);
	else if (g_spec->j == 1)
		num = va_arg(arg, uintmax_t);
	else if ( g_spec->ll == 0 &&  g_spec->l == 0)
	    num = va_arg(arg, unsigned int);
	display_u(num, base);
}