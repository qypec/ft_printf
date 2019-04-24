#include <stdio.h>
#include <unistd.h>
// #include "libft/libft.h"
# include <stdarg.h>

// void three( va_list arg)
// {
// 	int x = va_arg(arg, int);
// 	printf ("x = %d\n",x);
// }
// void one (int a, ...)
// {
// 	va_list arg;

// 	va_start(arg, (int) a);
// 	three(arg);
// 	three(arg);
// 	va_end (arg);

//}

int main()
{
	long int a = 9223372036854775807;

	printf ("%lo",a);
	return (0);
}