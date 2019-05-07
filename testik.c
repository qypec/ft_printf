#include <stdio.h>

int main ()
{
   	//printf("%1.d\n", 42);
	//printf("% d", 42949672);
	unsigned  long int  x;
	x = (unsigned long)-4294967296;
	printf("%jx\n", x);
	printf ("%lu\n", x);
    return (0);
}
