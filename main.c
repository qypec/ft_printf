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
	printf ("ft_size = %d", ft_printf("42% 017f42", -1.42));
	printf("\n");
	printf ("size = %d",printf("42% 017f42", -1.42));
	return (0)	;
}
