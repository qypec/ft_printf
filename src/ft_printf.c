/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:05 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/25 13:38:18 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				print_struct(t_spec	*spec) /* на время отладки */
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

static int			take_str_before_persent(char **traverse)
{
	char			*trav;

	trav = *traverse;
	while (*trav != '%' && *trav != '\0')
	{
		if (*trav == '{')
			trav = take_color(trav); // переписать
		if (*trav == '\0')
			break ;
		addsymb_glbuffer(*trav);
		trav++;
	}
	*traverse = trav;
	if (*trav == '\0')
		return (END_OF_STRING);
	return (0);
}

static void			output(size_t *size)
{
	if (g_output->error == -1)
		*size = -1;
	else
		*size = g_output->size;
	write (1, g_output->str, g_output->size);
}

static void			totalfree(void)
{
	free_bufferoutput();
	free(g_width);
	gspecfree();
	g_output = NULL;
	g_width = NULL;
}

int					ft_printf(const char *format, ...)
{
	va_list 		arg;
	char 			*traverse;
	size_t			size;
	
	if (!(g_width = malloc(sizeof(t_widt))))
		return (0);
	if (!(traverse = (char *)format))
		return (0);
	init_bufferoutput();
	va_start(arg, (char *)format);
	while (*traverse != '\0')
	{
		if (g_output->error == -1)
			break ; 
		if (take_str_before_persent(&traverse) == END_OF_STRING) /* берет символы до % */
			break ;
		struct_spec(&traverse);  /* записывает в структуру спецификатор */
		// print_struct(g_spec);
		print_arg(traverse, arg);
	}
	output(&size);
	totalfree();
	va_end(arg);
	return (size);
}
