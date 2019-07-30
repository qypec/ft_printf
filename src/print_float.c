/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/30 22:29:30 by oargrave         ###   ########.fr       */
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

	i = 0;
	number = (unsigned long long)num;
	ft_buff_addstr (part->middle, ft_itoa_u(number));
	ft_buff_addsymb(part->middle, '.');
	while (i < g_spec->precision + 3)
	{
		number = (double)num * 10;
		num *= 10;
		num -= number;
		ft_buff_addsymb(part->middle, number + 48);
		i++;
	}
}

void getfirst(t_part *part)
{
	int size_zero;
	int size_middle;
	int i;
 
	i = 0;
	if (g_spec->minus == 0)
	{
		if (g_spec->zero)
		{
			if (g_spec->plus && !(part->is_neg))
				part->first[i++] = '-';
			if (part->is_neg)
				part->first[i++] = '-';
			size_middle = ft_strlen(part->middle->str);
			size_zero = g_spec->width - size_middle;
			if ((part->first = (char *)malloc(sizeof(char) * size_zero)) == NULL)
				exit(-1);
			while (i < size_zero)
			{
				part->first[i] =  '0';
				i++;
			}
		}
		else
		{
			size_middle = ft_strlen(part->middle->str);
			size_zero = g_spec->width + 1 - size_middle;
			if ((part->first = (char *)malloc(sizeof(char) * size_zero)) == NULL)
				exit(-1);
			while (i < size_zero)
			{
				part->first[i] =  ' ';
				i++;
			}
			if (g_spec->plus && !(part->is_neg))
				part->first[i++] = '-';
			if (part->is_neg)
				part->first[i++] = '-';
		}
		
	}
}

void getend(t_part *part)
{
	int num_indents;
	int size_buff;
	int i;

	size_buff = ft_strlen(part->middle->str) + ft_strlen(part->first);
	num_indents = g_spec->width - size_buff;
	i = 0;
	if (g_spec->minus == 0)
		part->last = NULL;
	else
	{
		while (i < num_indents)
		{
			ft_buff_addsymb(part->middle, ' ');
			i++;
		}
	}
	
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
	ft_rounding(part->middle->str, ft_strlen(part->middle->str));
	getfirst(part);
	getend(part);
}
