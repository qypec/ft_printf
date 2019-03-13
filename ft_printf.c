#include <stdio.h>



#include "header.h"

static void		conclusion(char *step, va_list arg);
static int		fetching_args(char **step, va_list arg);

int		ft_printf(const char *format, ...)
{
	va_list arg;
	unsigned int i;
	char *str;

	va_start(arg, (char *)format);
	if (validity((char *)format, arg) == -1)
		return (-1);
	// conclusion((char *)format, arg)
	va_end(arg);
	
	return (0);
}

static void		conclusion(char *step, va_list arg)
{
	while (*step != '\0')
	{
		while (*step != '%' && *step != '\0')
		{
			ft_putchar(*step);
			step++;
		}
		if (*step == '\0')
			break;
		if (*step == '%')
		{
			step++;
			if (fetching_args(&step, arg) == 0)
				step++;
		}
	}
}

static int		fetching_args(char **step, va_list arg)
{
	if (**step == '%')
	{
		ft_putchar('%');
		return (0);
	}
	return (1);
}

int main()
{
	// char *a;

	// printf("настоящий printf = %p\n\n", a);
	/*printf("%d\n", */ft_printf("hello printf %d hello printf");

}