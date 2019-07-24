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
	char one[] = "3.140000";
	char two[] = "3.149999";
	printf("%.3f\n",3.149999);
	return (0)	;
}
