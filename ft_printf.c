#include <stdio.h>


#include "header.h"

// int		is_servicesymbol(char *traverse)
// {
// 	if (ft_isdigit(*traverse) != 1 && *traverse != ' ' && *traverse != 'L')
// 		return (0);
// 	if (*traverse != '#' && *traverse != '-' && *traverse != '+')
// 		return (0);
// 	if (*traverse == 'l')
// 	{
// 		if (*(traverse + 1) == 'l' && *(traverse + 2) == 'l')
// 			return (0);
// 	}
// 	if (*traverse == 'h')
// 	{
// 		if (*(traverse + 1) == 'h' && *(traverse + 2) == 'h')
// 			return (0);
// 	}
// 	return (1);
// }

// int		is_perсent_again(char *traverse)
// {
// 	while (*traverse != '%')
// 	{
// 		if (is_servicesymbol(traverse) == 1)
// 			traverse++;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

char	*print_before_specifier(char *traverse)
{
	while (*traverse != '%' && *traverse != '\0')
	{
		ft_putchar(*traverse);
		traverse++;
	}
	return (traverse);
}

int		ft_printf(const char *format, ...)
{
	va_list 		arg;
	t_spec			spec;
	char 			*traverse;
	int				len;

	traverse = (char *)format;
	len = 0;
	va_start(arg, (char *)format);
	while (*traverse != '\0')
	{
		traverse = print_before_specifier(traverse); /* печатает символы до % */
		len += traverse - format;
		if (*traverse == '\0')
			return (len);
		// if ((spec = struct_specifier(traverse, &spec)) == NULL)  записывает в структуру спецификатор 
		// {
		// 	// bust
		// 	return (len);
		// }
		// traverse = move_after_specifier(traverse);
		// len += print_arg(spec, arg); /*  */
		// freestruct(spec);
	}
	va_end(arg);
	return (len);
}

int main()
{
	// char *a;
	printf("настоящий:\n");
	printf("len = %d\n", printf("hello printf %f akfoa", 5));
	printf("own:\n");
	printf("len = %d\n", ft_printf("hello printf "));

}