#include "header.h"

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

int				ft_printf(const char *format, ...)
{
	va_list 		arg;
	t_spec			spec;
	char 			*traverse;
	size_t			size;
	g_width = malloc(sizeof(g_width));

	init_bufferoutput();
	traverse = (char *)format;
	va_start(arg, (char *)format);
	while (*traverse != '\0')
	{
		spec = (t_spec){(char)48, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0};
		g_spec = &spec;
		g_width->zero = 0;
		g_width->space_left = 0;
		g_width->space_right = 0;
		g_width->width = 0;
		traverse = take_str_before_persent(traverse); /* берет символы до % */
		if (*traverse == '\0')
			break ;
		traverse = struct_spec(++traverse);  /* записывает в структуру спецификатор */
		// print_struct(&spec);
		print_arg(traverse, arg);
	}
	va_end(arg);
	size = g_output->size;
	write(1, g_output->str, g_output->size);
	free_bufferoutput();
	return (size);
}
