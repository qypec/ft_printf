#include <stdio.h>

int main ()
{
	long long int a = 25500000;
	long long int b = (int)a;
	char one = a;
	char unsigned two = a;
	long long int  index = 9223372036854775807;
	unsigned width = -42;
	unsigned int str;
	// while (index > 0)
	// {
	// 	index = index / 16;
	// 	width++;
	// }
	str = width;
	printf ("%x\n",str);
	printf ("%d\n",str);
	return (0);
}