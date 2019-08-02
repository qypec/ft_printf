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
	ft_printf("{red}red{green}green{yellow}yellow{blue}blue{magenta}magenta{cyan}cyan{reset}\n");
	ft_printf("date: %k\n");
	
	char	**matr;
	matr = (char **)malloc(sizeof(char *) * 3);
	matr[0] = (char *)ft_memalloc(sizeof(char) * 2);
	matr[1] = (char *)ft_memalloc(sizeof(char) * 3);
	matr[0][0] = '1';
	matr[1][0] = 'a';
	matr[1][1] = 'b';
	matr[2] = NULL;
	ft_printf("matr: \n%w\n", matr);
	ft_printf("%d\n", 0);
	ft_printf("%f\n", 0);
	ft_printf("%i\n", 0);
	ft_printf("%u\n", 0);
	ft_printf("%x\n", 0);
	ft_printf("%X\n", 0);
	ft_printf("%e\n", 0);
	ft_matrixfree(&matr);
	return (0);
}
