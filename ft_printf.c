#include "header.h"

void	print_struct(t_spec	*spec) /* на время отладки */
{
	printf("\n");
	printf("symb = %c\n", spec->symb);
	printf("width = %d\n", spec->width);
	printf("space = %d\n", spec->space);
	printf("sharp = %d\n", spec->sharp);
	printf("plus = %d\n", spec->plus);
	printf("minus = %d\n", spec->minus);
	printf("zero = %d\n", spec->zero);
	printf("precision = %d\n", spec->precision);
	printf("L = %d\n", spec->big_l);
	printf("ll = %d\n", spec->ll);
	printf("l = %d\n", spec->l);
	printf("hh = %d\n", spec->hh);
	printf("h = %d\n", spec->h);
	printf("\n");
}

char	*move_after_specifier(char *traverse)
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

char	*print_before_specifier(char *traverse, int *len)
{
	while (*traverse != '%' && *traverse != '\0')
	{
		ft_putchar(*traverse);
		traverse++;
		(*len)++;
	}
	return (traverse);
}

int		ft_printf(const char *format, ...)
{
	va_list 		arg;
	t_spec			spec;
	char 			*traverse;
	int				len;

	len = 0;
	init_bufferoutput();
	printf("global = %s\n", gl_output->str);
	// traverse = (char *)format;
	// va_start(arg, (char *)format);
	// while (*traverse != '\0')
	// {
	// 	spec = (t_spec){(char)48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	// 	traverse = print_before_specifier(traverse, &len); /* печатает символы до % */
	// 	if (*traverse == '\0')
	// 		return (len);
	// 	spec = struct_specifier(++traverse, &spec);  /* записывает в структуру спецификатор */
	// 	// print_struct(&spec);
	// 	len += print_arg(traverse, &spec, arg);
	// 	traverse = move_after_specifier(traverse);
	// }
	va_end(arg);
	return (len);
}
