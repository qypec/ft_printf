#include "header.h"

int main()
{
	// printf("real:\n");
	// printf("%5.5s", "hello world");
	// printf("\nreal:\n");
	// printf ("len = |%d|",printf("%+10.3d",48));
	// printf ("\nown\n");
	// printf("len = |%d|",ft_printf("%+10.3d", 48));
	// printf("\n\n\n\n\n\n\n");
	// printf("\nreal:\n");
	// printf ("len = |%d|",printf("%+.10d",48));
	// printf ("\nown\n");
	// printf("len = |%d|",ft_printf("%+.10d", 48));
	// printf("\n\n\n\n\n\n\n");
	printf("\nreal:\n");
	printf ("len = |%d|",printf("%0+5d", 42));
	printf ("\nown\n");
	printf("len = |%d|",ft_printf("%0+5d", 42));
	return (0);
}
