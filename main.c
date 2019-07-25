#include "includes/header.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <math.h>


int main()
{
	char one[] = "3.140000";
	char two[] = "333333333333333333.14999964745545456";
	ft_printf("%f\n", -1.42);
	printf("\n");
	printf("%f\n", -1.42);
	int nb = 1;
	printf("original:\n");
	printf("| size = %d |\n", printf("1 -> %.05d\n", nb));
	printf("my:\n");
	printf("| size = %d |\n", ft_printf("1 -> %.05d\n", nb));
	return (0)	;
}
