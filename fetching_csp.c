#include "header.h"

void	fetching_csp(char *step, va_list arg)
{
	if (*step == 'c')
	{
		ft_putchar(va_arg(arg, int));
	}
	if (*step == 's')
	{
		ft_putstr(va_arg(arg, char *));
	}
	// if (*step == 'p')
	// {
	// 	ft_putstr(va_arg(arg, void *));
	// 	break;
	// }
}