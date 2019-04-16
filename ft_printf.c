#include <stdio.h>


#include "header.h"

char	*print_before_specifier(char *traverse)
{
	while (*traverse != '\0')
	{

		traverse++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list 		arg;
	t_spec			*spec;
	char 			*traverse;

	traverse = format;
	va_start(arg, (char *)format);
	while (*traverse != '\0')
	{
		traverse = print_before_specifier(traverse);
		spec = struct_specifier(traverse);
		print_arg(spec, arg);
		traverse = move_after_specifier(traverse);
		// freestruct(spec);
	}

	// if (spec->symb == 'd' || spec->symb == 'i' || spec->symb == 'o' || spec->symb == 'x')
	// {

	// }
	// else if (spec->symb == 'c')
	// {

	// }
	// else if (spec->symb == 's')
	// {

	// }
	// while (traverse != NULL)
	// {
		// while (*traverse != '%')
		// {
			// ft_putchar(*traverse);
			// traverse++;
		// }
	va_end(arg);	
	return (0);
}

int main()
{
	// char *a;

	// printf("настоящий printf = %p\n\n", a);
	printf("validity = %d\n", ft_printf("hello printf %    d"));

}