/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:05 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/23 14:01:51 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			print_struct(t_spec	*spec) /* на время отладки */
{
	printf("\n");
	printf("symb = %c\n",  g_spec->symb);
	printf("width = %d\n",  g_spec->width);
	printf("space = %d\n",  g_spec->space);
	printf("sharp = %d\n",  g_spec->sharp);
	printf("plus = %d\n",  g_spec->plus);
	printf("minus = %d\n",  g_spec->minus);
	printf("zero = %d\n",  g_spec->zero);
	printf("precision = %d\n",  g_spec->precision);
	printf("L = %d\n",  g_spec->big_l);
	printf("ll = %d\n",  g_spec->ll);
	printf("l = %d\n",  g_spec->l);
	printf("hh = %d\n",  g_spec->hh);
	printf("h = %d\n",  g_spec->h);
	printf("z = %d\n",  g_spec->z);
	printf("j = %d\n",  g_spec->j);
	printf("\n");
}

char			*move_after_specifier(char *traverse)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == '|')
		{
			traverse++;
			while (*traverse != '|')
				traverse++;
		}
		traverse++;
	}
	if (*traverse == '\0')
		return (traverse);
	traverse++;
	return (traverse);
}

static char		*take_str_before_persent(char *traverse)
{
	while (*traverse != '%' && *traverse != '\0')
	{
		if (*traverse == '{')
			traverse = take_color(traverse);
		if (*traverse == '\0')
			break ;
		addsymb_glbuffer(*traverse);
		traverse++;
	}
	return (traverse);
}

static void init_gspec()
{
	if (g_spec == NULL)
		if (!(g_spec = malloc(sizeof(t_spec))))
			return ;
	g_spec->symb = (char)48;
	g_spec->width = 0;
	g_spec->space = 0;
	g_spec->sharp = 0;
	g_spec->plus = 0;
	g_spec->minus = 0;
	g_spec->zero = 0;
	g_spec->precision = -1;
	g_spec->big_l = 0;
	g_spec->ll = 0;
	g_spec->l = 0;
	g_spec->j = 0;
	g_spec->hh = 0;
	g_spec->h = 0;
	g_spec->z = 0;
	g_width->zero = 0;
	g_width->space_left = 0;
	g_width->space_right = 0;
	g_width->width = 0;
}

int				ft_printf(const char *format, ...)
{
	va_list 		arg;
	t_spec			spec;
	char 			*traverse;
	size_t			size;
	
	if (!(g_width = malloc(sizeof(t_widt))))
		return (0);
	init_bufferoutput();
	if (!(traverse = (char *)format))
		return (0);
	va_start(arg, (char *)format);
	while (*traverse != '\0')
	{
		if (g_output->error == -1)
			break ; 
		init_gspec();
		traverse = take_str_before_persent(traverse); /* берет символы до % */
		if (*traverse == '\0')
			break ;
		traverse = struct_spec(++traverse);  /* записывает в структуру спецификатор */
		// print_struct(&spec);
		print_arg(traverse, arg);
	}
	va_end(arg);
	if (g_output->error == -1)
	{
		size = -1;
		write (1, g_output->str, g_output->size);
	}
	else	
	{
		size = g_output->size;
		write(1, g_output->str, g_output->size);
	}
	free_bufferoutput();
	free(g_width);
	free(g_spec);
	g_output = NULL;
	g_width = NULL;
	g_spec= NULL;
	return (size);
	
}
