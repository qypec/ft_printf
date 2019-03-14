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
	conclusion((char *)format, arg)
	va_end(arg);
	
	return (0);
}

static char		*read_specifier(const char *step)
{
	char	*specifier;
	int		len;

	len = ft_strlenchr(step, '%');
	specifier = (char *)malloc(sizeof(char) * (len + 1));
	specifier = ft_strncpy(specifier, step, len + 1);
	// if (specifier[len] == '%')
	// 	specifier[len] = '\0';
	return (specifier);
}

static void		conclusion(char *step, va_list arg)
{
	char *specifier;

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
			specifier = read_specifier(step++);
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
	printf("validity = %d\n", ft_printf("hello printf %    d"));

}