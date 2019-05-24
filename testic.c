#include <stdio.h>
#include <stdlib.h>

int main ()
{
	long double test = 125.155578;
	long double test2;
	int integer_part;
	char *mas = malloc(sizeof(char) * 11); //  тест на дабл состоящий из 9 разрядов и точки 
	int index = 0;
	test2 = test / 1000;
	while (index != 10)
	{
		mas[index] = (long long)(test2 * 10) + 0x30;
		test2 *= 10;
		integer_part = (long long int) test2;
		test2 -= integer_part;
		index++;
		if (index == 3)
		{
			mas[index] = '.';
			index++;
		}

	}
	mas[index] = '\0';
	printf ("\n%s\n", mas);
	printf ("%Lf\n", test);
	free(mas);
	return (0);
}