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
	// ft_printf("{red}red{green}green{yellow}yellow{blue}blue{magenta}magenta{cyan}cyan{reset}\n");
	// ft_printf("date: %k");
	
	char	**matr;

	matr = (char **)malloc(sizeof(char *) * 3);
	matr[0] = (char *)ft_memalloc(sizeof(char) * 2);
	matr[1] = (char *)ft_memalloc(sizeof(char) * 3);
	matr[0][0] = '1';
	matr[1][0] = 'a';
	matr[1][1] = 'b';
	matr[2] = NULL;
	ft_printf("%w", matr);

	
	return (0);
}
