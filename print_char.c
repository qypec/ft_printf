/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:42:07 by oargrave          #+#    #+#             */
/*   Updated: 2019/05/20 16:57:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_c(va_list arg)
{
	char symbol;

	symbol = (char)va_arg(arg, int);
	if (symbol == 0)
	{
		width(1, " ");
		print_width(1);
		addsymb_glbuffer(symbol);
	}
	else
	{
		width(1, " ");
		print_width(1);
		addsymb_glbuffer(symbol);
		print_width_end();
	}
}

int		print_s(va_list arg, char *str, char *ptr, char *point)
{
	int	index;

	index = 0;
	str = (char *)va_arg(arg, void *);
	if (str == NULL)
	{
		str = ft_strcpy(ft_strnew(6), NUL);
		point = str;
	}
	if (g_spec->precision >= 0 && g_spec->precision < (int)ft_strlen(str))
	{
		ptr = ft_strnew(g_spec->precision);
		while (index != g_spec->precision)
			ptr[index++] = ' ';
		ptr[g_spec->precision] = '\0';
		ptr = ft_strncpy(ptr, str, g_spec->precision);
		str = ptr;
	}
	width(1, str);
	print_width(1);
	update_glbuffer(str);
	print_width_end();
	ft_memdel((void *)&ptr);
	ft_memdel((void *)&point);
	return (0);
}

void	print_p(va_list arg)
{
	long long int	num;
	char			*str;

	num = va_arg(arg, long long int);
	if (num < 0)
		num = -num;
	str = ft_itoa_base(num, 16);
	width(num, str);
	print_width(num);
	update_glbuffer(str);
	print_width_end();
	free(str);
	return ;
}

void	print_char(va_list arg)
{
	if (g_spec->symb == 'c')
		print_c(arg);
	if (g_spec->symb == 's')
		print_s(arg, NULL, NULL, NULL);
	if (g_spec->symb == 'p')
		print_p(arg);
	return ;
}
