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
	int a = 10;
	printf("\nreal:\n");
	printf ("len = |%d|", printf("%lu", -42));
	printf ("\nown\n");
	printf("len = |%d|", ft_printf("%lu", -42));

	return (0);
}
