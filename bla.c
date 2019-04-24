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
	char s[] = "denis hello world";
	char c = 'a';
	int a = 13445;
	printf ("\nsize = %d",printf ("%-30s",s));
	return (0);
}