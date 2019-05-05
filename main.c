#include "header.h"

int main()
{
	time_t ttime;

	ttime = time(NULL);
	// printf("real:\n");
	// printf("%5.5s", "hello world");
	// printf("\nown:\n");
	ft_printf("%|DD| |   MNH| |YYY| |WDA| || |hh|:|mm|:|ss|k", ttime);
	return (0);
}
