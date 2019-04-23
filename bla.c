#include <stdio.h>
#include <stdlib.h>

void	lenf(int *len)
{
	(*len)++;
}

int main()
{
	int *len;

	len = (int *)malloc(sizeof(int) * 1);
	*len = 0;
	lenf(len);
	printf("%d", *len);
}