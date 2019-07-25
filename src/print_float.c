/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/25 17:39:05 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"


static void	float_copy(char *numb, char *str, int i, int size_str)
{
	int j;
	char *result;

	j = 0;
	if (!(result = (char *)malloc(sizeof(char) * (i + size_str + 3))))
		return ;
	i = 0;
	if (g_spec->minus == 2)
		result[i++] = '-';
	while (str[j] != '\0')
		result[i++] = str[j++];
	j = 0;
	while (numb[j] != '\0')
		result[i++] = numb[j++];
	
	result[i] = '\0';
	width(0, result);
	print_width(0);
	ft_rounding(result, i);
	update_glbuffer(result);
	free(str);
	free(numb);
	free(result);
}

void	print_float(long double num, int i, int j, int size_str)
{
	unsigned long long number;
	char *str;
	char *numb;
	char *result;

	number = (unsigned long long)num;
	str = ft_itoa_u(number);
	size_str = ft_strlen(str);
	num -= number;
	numb = (char *)malloc(sizeof(char) * (size_str + g_spec->precision + 3));
	if (g_spec->precision > 0 || g_spec->sharp == 1)
	{
		numb[i] = '.';
		i++;
	}
	while (i < g_spec->precision + 3)
	{
		number = (double)num * 10;
		num *= 10;
		num -= number;
		numb[i] = number + 48;
		i++;
	}
	numb[i] = '\0';
	float_copy(numb, str, i, size_str);
}

void assembl_float(va_list arg)
{
	long double  num;
	
	if (g_spec->precision < 0)
		g_spec->precision = 6;
	if (g_spec->symb == 'f' && g_spec->big_l == 0)
		num = va_arg(arg, double);
	else if (g_spec->big_l == 1)
		num = va_arg(arg, long double);
	if (num < 0)
	{
		num *= -1;
		g_spec->minus = 2;
	}
	print_float(num, 0, 0, 0);
}