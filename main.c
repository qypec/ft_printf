#include "header.h"

int main()
{
	printf("real:\n");
	printf("%#08x", 42);
	printf("\nown:\n");
	ft_printf("%#08x", 42);
	printf("\n");
	return (0);
}