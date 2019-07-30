/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/30 20:16:40 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.h"


static char*	width_float_two(char *result, int size_result, int i, int j)
{
	char *result_new;
	
	result_new = (char *)malloc(sizeof(char) * g_spec->width + 1);
	if (g_spec->zero == 1 && !(g_spec->minus))
	{
		if (g_spec->is_neg)
			result_new[i++] = '-';
		if (!(g_spec->is_neg) && g_spec->plus)
			result_new[i++] = '+';
		while (i < g_spec->width)
			result_new[i++] = '0';
	}
	else if (!(g_spec->minus) || g_spec->is_neg)
	{
		while (i < g_spec->width)
			result_new[i++] = ' ';
	}
	else if (g_spec->minus )
	{
		
	}
	return (result_new);
}

static char*	width_float(char *result, int size_result)
{
	int size;
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (g_spec->is_neg || (g_spec->plus && !(g_spec->is_neg)))
		size_result++;
	if (g_spec->width <= size_result)
	{
		if (g_spec->is_neg)
			addsymb_glbuffer('-');
		if (!(g_spec->is_neg) && g_spec->plus)
			addsymb_glbuffer('+');
		return (result);
	}
	else if (g_spec->width > size_result)
		result = width_float_two(result, size_result, i, j);
	return (result);		
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

char	*getnumber(t_part *part, long double num)
{
	unsigned long long number;

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

void	print_float1(va_list arg)
{
	long double  num;
	t_part			*part;

	init_part(part);	
	if (g_spec->precision  == -1)
		g_spec->precision = 6;
	if (g_spec->big_l == 0)
		num = va_arg(arg, double);
	else 
		num = va_arg(arg, long double);
	if (num < 0)
	{
		num *= -1;
		part->is_neg = 1;
	}
	getnumber(part, num);
	getfirst(part);
	getend(part);
}
