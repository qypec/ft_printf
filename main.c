#include "header.h"

int main()
{
	printf("real:\n");
	printf("%-5.10o", 2500);
	printf("\nown:\n");
	ft_printf("%-5.10o", 2500);
	printf("\n");
	return (0);
}