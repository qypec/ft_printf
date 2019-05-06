#include "header.h"

int main()
{
	time_t ttime;

	ttime = time(NULL);
	// printf("real:\n");
	// printf("%5.5s", "hello world");
	// printf("\nown:\n");
	printf("original:\n% -+40%\n");
	printf("own:\n");
	ft_printf("% -+40%");
	return (0);
}
