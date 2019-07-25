/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/25 10:56:40 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_float(long double num)
{
	unsigned long long number;
	char *str;
	char *numb;
	char *result;
	int i;
	int size_str;
	int j;

	j = 0;
	i = 0;
	if (g_spec->precision < 0)
		g_spec->precision = 6;
	if (num < 0)
	{
		num *= -1;
		g_spec->minus = 1;
	}
	number = (unsigned long long)num;
	str = ft_itoa_u(number);
	size_str = ft_strlen(str);
	num -= number;
	if (!(numb = (char *)malloc(sizeof(char) * (size_str + g_spec->precision + 3))))
		return ;
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
	result = (char *)malloc(sizeof(char) * (i + size_str + 3));
	i = 0;
	if (g_spec->minus == 1)
	{
			result[i] = '-';
			i++;
	}
	while (str[i] != '\0')
	{	
		result[i] = str[i];
		i++;
	}
	while (numb[j] != '\0')
	{
		result[i] = numb[j];
		i++;
		j++;
	}
	result[i] = '\0';
	width(0, result);
	print_width(0);
	ft_rounding(result, i);
	update_glbuffer(result);
	free(str);
	free(numb);
	free(result);
}

void assembl_float(va_list arg)
{
	long double  num;

	if (g_spec->symb == 'f' && g_spec->big_l == 0)
		num = va_arg(arg, double);
	else if (g_spec->big_l == 1)
		num = va_arg(arg, long double);

	// printf ("%Lf", num);
	print_float(num);
}