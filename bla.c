#include <stdio.h>
typedef void (*sort) ();

void one (int a)
{
	printf("%d\n",a);
}

void two (int b )
{
	printf ("%d\n",b + 1);
}

 void three(int a, void print(int a))
 {
 	print(a);
 }
int main()
{
	sort *a;
	a =  (sort*)malloc(sizeof(sort) * 3);
	three(4, one);
	three(4, two);
	printf("% l%");
	printf("");
}