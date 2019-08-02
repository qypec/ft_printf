/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/02 12:39:00 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	getnumber(t_part *part, long double num)
{
	unsigned long long		number;
	int						i;
	char					str[2];

	str[1] = '\0';
	i = 0;
	number = (unsigned long long)num;
	num -= number;
	ft_buffadd(part->middle, ft_itoa_u(number));
	if (g_spec->precision != 0 || g_spec->sharp == 1)
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


static t_part	*init_part(t_part *part)
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

void		del_part(t_part *part)
{
	if (part->first != NULL)
		free(part->first);
	if (part->last != NULL)
		free(part->last);
	if (part->middle != NULL)
		ft_buffdel(&part->middle);
	free(part);
	part = NULL;
}

void	fill_parts_float(t_part *part, long double num)
{
	getnumber(part, num);
	ft_rounding(part->middle->str, ft_strlen(part->middle->str) - 1, part);
	getfirst(part, ft_strlen(part->middle->str));
	getend(part);
	update_glbuffer(part->first);
	update_glbuffer(part->middle->str);
	update_glbuffer(part->last);
	del_part(part);
}

void	print_float(va_list arg)
{
	long double		num;
	t_part			*part;
	lnum			bit;

	part = init_part(part);
	part->middle = ft_buffinit(10);
	if (g_spec->precision == -1)
		g_spec->precision = 6;
	if (g_spec->big_l == 0)
		num = va_arg(arg, double);
	else
		num = va_arg(arg, long double);
	bit.f = num;
	if (bit.t_bit_float.sign == 1)
	{
		num *= -1;
		part->is_neg = 1;
	}
	fill_parts_float(part, num);
}