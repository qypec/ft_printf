/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:21:48 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/20 17:36:37 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char					*register_x(char *str)
{
	int		index;

	index = 0;
	if (g_spec->symb == 'x')
		while (str[index])
		{
			if (str[index] >= 65 && str[index] <= 70)
				str[index] = str[index] + 32;
			index++;
		}
	if (g_spec->symb == 'X')
		while (str[index])
		{
			if (str[index] >= 97 && str[index] <= 122)
				str[index] = str[index] - 32;
			index++;
		}
	return (str);
}

void					sign_x(long long int num)
{
	if (g_spec->symb == 'x' || g_spec->symb == 'X' || g_spec->symb == 'p')
	{
		if (g_spec->sharp == 1 && num > 0)
		{
			if (g_spec->symb == 'x')
				addstr_glbuffer("0x", 2);
			else if (g_spec->symb == 'X')
				addstr_glbuffer("0X", 2);
		}
		if (g_spec->symb == 'p')
			addstr_glbuffer("0x", 2);
	}
	else if (g_spec->symb == 'o')
	{
		if (g_spec->sharp == 1 && (num != 0 || g_spec->precision == 0))
		{
			g_width->zero--;
			addsymb_glbuffer('0');
		}
	}
}

void					sign(long long int num)
{
	if (g_spec->plus == 1 && num >= 0 && g_spec->symb != 'u')
	{
		addsymb_glbuffer('+');
		g_width->space_left--;
		g_width->space_right--;
		if (g_spec->precision <= 0)
			g_width->zero--;
	}
	if (num < 0)
		addsymb_glbuffer('-');
	if (g_spec->symb == 'p')
		addstr_glbuffer("0x", 2);
	if (g_spec->symb == 'o')
	{
		if (g_spec->sharp == 1 && (num != 0 || g_spec->precision == 0))
		{
			g_width->zero--;
			addsymb_glbuffer('0');
		}
	}
	if (g_spec->symb == 'x' || g_spec->symb == 'X')
		sign_x(num);
}

void					display_int(long long int num, int base)
{
	char			*str;
	long long int	num1;

	num = reduction_signed(num, 0);
	num1 = num;
	if (num < 0)
		num = -num;
	if (num == 0 && g_spec->precision >= 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base(num, base);
	width(num1, str);
	print_width(num1);
	if (g_spec->precision >= 0 && num == 0)
	{
		print_width_end();
	}
	else
	{
		update_glbuffer(str);
		print_width_end();
	}
	free(str);
}

void					print_width_end(void)
{
	int			index;

	index = 0;
	if (g_width->space_right > 0)
	{
		while (index < g_width->space_right)
		{
			addsymb_glbuffer(' ');
			index++;
		}
	}
	return ;
}