/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:36:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 12:40:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		print_c(va_list arg)
{
	char		symbol;

	symbol = (char)va_arg(arg, int);
	if (symbol == 0)
	{
		width(1, " ");
		print_width(1);
		addsymb_glbuffer(symbol);
		print_width_end();
	}
	else
	{
		width(1, " ");
		print_width(1);
		addsymb_glbuffer(symbol);
		print_width_end();
	}
}

int			check_str(char *str)
{
	int			index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < 0 || str[index] > 127)
		{
			g_output->error = -1;
			return (-1);
		}
		index++;
	}
	return (1);
}

static int	print_else(char *str, char *ptr, char *point)
{
	if ((check_str(str) == -1))
		return (-1);
	if (g_spec->precision >= 0 && (g_spec->precision < ft_strlen(str)))
	{
		ptr = ft_strnew(g_spec->precision);
		ptr = ft_strncpy(ft_strnew(g_spec->precision), str, g_spec->precision);
	}
	else
		ptr = ft_strdup(str);
	width(1, ptr);
	print_width(1);
	update_glbuffer(ptr);
	print_width_end();
	free(ptr);
	return (0);
}

int			print_s(va_list arg, char *str, char *ptr, char *point)
{
	str = (char *)va_arg(arg, void *);
	if (str == NULL)
	{
		if (g_spec->precision >= 0 && (g_spec->precision < NULL_SIZE))
		{
			ptr = ft_strnew(g_spec->precision);
			ptr = ft_strncpy(ptr, NUL, g_spec->precision);
		}
		else
			ptr = ft_strdup(NUL);
		width(1, ptr);
		print_width(1);
		update_glbuffer(ptr);
		print_width_end();
		free(ptr);
	}
	else
	{
		if ((print_else(str, ptr, point) == -1))
			return (-1);
	}
	return (0);
}

void		print_p(va_list arg)
{
	long long int	num;
	char			*str;
	unsigned long long a;

	num = va_arg(arg, long long int);
	if (num < 0)
	{
		a = (unsigned long long)num;
		str = ft_itoa_base(a, 16);
		width(a, str);
		print_width(a);
	}
	else
	{
		str = ft_itoa_base(num, 16);
		width(num, str);
		print_width(num);
	}
	if (g_spec->precision != 0 || str[0] != '0')
		update_glbuffer(str);
	print_width_end();
	free(str);
	return ;
}

void		print_char(va_list arg)
{
	if (g_spec->symb == 'c')
		print_c(arg);
	if (g_spec->symb == 's')
		print_s(arg, NULL, NULL, NULL);
	if (g_spec->symb == 'p')
		print_p(arg);
	return ;
}
