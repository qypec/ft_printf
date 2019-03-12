#include <stdio.h>



#include "header.h"

static void fetching_args(char *step, va_list arg);

int		ft_printf(const char *format, ...)
{
	va_list arg;
	unsigned int i;
	char *str;

	va_start(arg, (char *)format);
	fetching_args((char *)format, arg);
	va_end(arg);
	
	return (0);
}

static void fetching_args(char *step, va_list arg)
{
	while (*step != '\0')
	{
		if (*step != '%')
			step++;
		else
		{
			
		}
		step++;

	}
}

int main()
{
	// char *a;

	// printf("настоящий printf = %p\n\n", a);
	printf("%d\n", ft_printf("не настоящий printf"));

}