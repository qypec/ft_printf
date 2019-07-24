/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:54 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/24 10:07:38 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_float(long double num)
{
	unsigned long long number;
	char *str;

	number = (unsigned long long)num;
	str = ft_itoa_u(number);
	// printf ("%s", str);
	printf ("%Lf\n", num);
	// num = num - number;
	// printf ("%f\n", num);
	// printf ("%lu\n", number);
	// printf ("%lf\n", num);
}

void assembl_float(va_list arg)
{
	long double  num;

	if (g_spec->symb == 'f' && g_spec->big_l == 0)
		num = va_arg(arg, double);
	else if (g_spec->big_l == 1)
		num = va_arg(arg, long double);
	print_float(num);
}