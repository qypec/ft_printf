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
	printf("original:\n");
	printf("| size = %d |\n", printf("1 -> %.05d\n", nb));
	printf("my:\n");
	printf("| size = %d |\n", ft_printf("1 -> %.05d\n", nb));
	return (0)	;
}
