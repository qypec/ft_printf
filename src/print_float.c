/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/30 15:31:38 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.h"


static char*	width_float_two(char *result, int size_result, int size, int *in)
{
	char *result_new;
	int i;

	i = *in;
	
	result_new = (char *)malloc(sizeof(char) * (size_result + size + 2));
	result[size_result + size + 1] = '\0';
	if (g_spec->zero == 1 && g_spec->minus != 1 && g_spec->minus != 3)
	{
		if (g_spec->minus == 2)
			addsymb_glbuffer('-');
		if (g_spec->plus == 1 && g_spec->minus != 2 )
			addsymb_glbuffer('+');
		while (i <= size - 1)
			result_new[i++] = '0';
	}
	else if (g_spec->minus == 0 || g_spec->minus == 2)
	{
		while (i < size)
			result_new[i++] = ' ';
		if (g_spec->minus == 2)
			result_new[i++] = '-';
		if (g_spec->minus != 2 && g_spec->plus == 1)
			result_new[i++] = '+';
	}
	else if (g_spec->minus == 1 || g_spec->minus == 3)
	{
		while (i < size + size_result)
			result_new[i++] = ' ';
		result_new[i] = '\0';
		if (g_spec->minus == 3)
			result_new[i++] = '-';
		if (g_spec->minus != 3 && g_spec->plus == 1)
			result_new[i++] = '+';
	}
	*in = i;
	return (result_new);
}

static char*	width_float(char *result, int size_result)
{
	char *result_new;
	int size;
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (g_spec->minus == 2 || g_spec->minus == 3 || (g_spec->plus == 1 && \
		g_spec->minus != 2 && g_spec->minus != 3))
		size_result++; 	
	size = g_spec->width - size_result;
	if (g_spec->width > g_spec->precision)
		result_new = width_float_two(result, size_result, size, &i);
	else
	{
		if (g_spec->minus == 2 || g_spec->minus == 3)
			addsymb_glbuffer('-');
		else if (g_spec->plus == 1)
			addsymb_glbuffer('+');
		return (result);
	}
	if (g_spec->minus == 3 || g_spec->minus == 1)
		i = 0;
	while (result[j] != '\0')
		result_new[i++] = result[j++];
	free (result);
	return (result_new);	
}

static void	float_copy(char *numb, char *str, int i, int size_str)
{
	int j;
	char *result;
	int size_result;

	j = 0;
	if (!(result = (char *)malloc(sizeof(char) * (i + size_str + 3))))
		return ;
	i = 0;
	while (str[j] != '\0')
		result[i++] = str[j++];
	j = 0;
	while (numb[j] != '\0')
		result[i++] = numb[j++];
	result[i] = '\0';
	ft_rounding(result, i);
	size_result = ft_strlen(result);
	result = width_float(result, size_result);
	if (g_spec->space == 1 && g_spec->plus != 1 && g_spec->minus != 2 && g_spec->minus != 3 && g_spec->width == size_result)
		addsymb_glbuffer(' ');
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
	numb[i++] = '.';
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
	
	if (g_spec->precision  == -1)
		g_spec->precision = 6;
	if (g_spec->big_l == 0)
		num = va_arg(arg, double);
	else 
		num = va_arg(arg, long double);
	if (num < 0)
	{
		num *= -1;
		g_spec->minus += 2;
	}
	print_float(num, 0, 0, 0);
}