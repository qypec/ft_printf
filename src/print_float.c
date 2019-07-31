/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/31 19:43:44 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.h"

void  fill_parts_float(t_part *part, long double num)
{

	
}

void	getnumber(t_part *part, long double num)
{
	unsigned long long number;
	int i;
	char str[2];

	str[1] = '\0';
	i = 0;
	number = (unsigned long long)num;
	num -= number;
	ft_buffadd(part->middle, ft_itoa_u(number));
	ft_buffadd(part->middle, ".");
	while (i < g_spec->precision + 3)
	{
		number = (double)num * 10;
		num *= 10;
		num -= number;
		str[0] = number + 48;
		ft_buffadd(part->middle, str);
		i++;
	}
}

void getfirst(t_part *part)
{
	int size_zero;
	int size_middle;
	int i;
 
	i = 0;
	size_middle = ft_strlen(part->middle->str);
	size_zero = g_spec->width - size_middle;
	if (size_zero <= 0)
	{	
		if ((part->first = (char *)malloc(sizeof(char) * 1)) == NULL)
			return ;
	}
	else if (size_zero > 0)
	{
		if ((part->first = (char *)malloc(sizeof(char) * size_zero + 1)) == NULL)
			return ;
	}
	if ((size_zero <= 0 || (size_zero && g_spec->zero == 1) || g_spec->minus == 1)
		&& !(g_spec->plus) && !(part->is_neg) && g_spec->space == 1)
		part->first[i++] = ' ';
	
	if (g_spec->minus == 1)
	{
		if (g_spec->plus && !(part->is_neg))
				part->first[i++] = '+';
			if (part->is_neg)
				part->first[i++] = '-';
	}
	if (g_spec->minus == 0)
	{
		if (g_spec->zero)
		{
			if (g_spec->plus && !(part->is_neg))
				part->first[i++] = '+';
			if (part->is_neg)
				part->first[i++] = '-';
			while (i < size_zero)
			{
				part->first[i] =  '0';
				i++;
			}
		}
		else
		{
			if ((g_spec->plus && !(part->is_neg)) || (part->is_neg))
				size_zero--;
			while (i < size_zero)
			{
				part->first[i] =  ' ';
				i++;
			}
			if (g_spec->plus && !(part->is_neg))
				part->first[i++] = '+';
			if (part->is_neg)
				part->first[i++] = '-';
		}
		
	}
	part->first[i] = '\0';
}

void getend(t_part *part)
{
	int num_indents;
	int size_buff;
	int i;

	size_buff = ft_strlen(part->middle->str) + ft_strlen(part->first);
	num_indents = g_spec->width - size_buff;

	part->last = (char *)malloc(sizeof(char) * num_indents + 1);
	if (!(part->last))
		return ;
	part->last[num_indents] = '\0';
	i = 0;
	if (g_spec->minus == 0)
		part->last = NULL;
	else
	{
		while (i < num_indents)
		{
			part->last[i] = ' ';
			i++;
		}
	}
	
}

t_part *init_part(t_part *part)
{
	part = (t_part *)malloc(sizeof(t_part));
	if (!part)
		exit(-1);
	part->is_neg = 0;
	part->first = NULL;
	part->last = NULL;
	part->middle = NULL;
	return (part);
}

void	print_float(va_list arg)
{
	long double  num;
	t_part			*part;

	part = init_part(part);
	part->middle = ft_buffinit(10);
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
	ft_rounding(part->middle->str, ft_strlen(part->middle->str) - 1 , part);
	getfirst(part);
	getend(part);
	update_glbuffer(part->first);
	update_glbuffer(part->middle->str);
	update_glbuffer(part->last);
}
