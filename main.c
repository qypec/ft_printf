#include "header.h"

int main()
{
	time_t	ttime;

	ttime = time(NULL);
	// printf("real:\n");
	// printf("%-5.10o", 2500);
	// printf("\nown:\n");
	ft_printf("%|MNH| |YYYY|k", ttime);
	printf("\n");
	return (0);
}