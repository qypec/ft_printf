#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
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
	int a = 10000;
	int index = a;
	int width = 0;
	// one(4,3,5,6,7);
	// // one(4,3,5,6,7);
	// //ft_putnbr(a);
	// printf ("%-d\n",a);
	// printf ("%d\n",a);
	// printf ("%5i\n",a);
	while (index > 0)
    {
        index = index / 10;
        width++;
    }
	ft_putnbr(23420);
	printf ("\n");
	// printf ("%d\n",width);
	// printf ("%6d\n",a);
	index = printf ("%--5.6o\n",1101);
	printf ("%d", index);
	// printf ("%0d\n",a);
	return (0);
}