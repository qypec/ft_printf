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


//fix parse size + espace + zero + prec:% 05.3d \n\n\n", nb

int main()
{
	int nb = 1;
	printf("%.05d\n", nb);
	ft_printf("%.05d\n", nb);
	return (0)	;
}
