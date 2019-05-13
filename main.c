#include "header.h"


#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// int main()
// {
//     int READING_SIZE =  500;
//     int        pipeans[2];
//     int        pipecor[2];
//     int        ians;
//     int        icor;
//     char    ans[READING_SIZE + 1];
//     char    cor[READING_SIZE + 1];
    
//     if (pipe(pipeans) == -1)
//         return (0);
//     if (dup2(pipeans[1], 1) == -1)
//         return (0);
//     if (pipe(pipecor) == -1)
//         return (0);
//     if (dup2(pipecor[1], 2) == -1)
//         return (0);
    
    
//     int        nb;
//     nb = 0;
//     printf("space% d ", nb);
//     printf("plus:%+d ", nb);
//     printf("precision:%.5d ", nb);
//     printf("space + prec:% .5d ", nb);
//     printf("Plus + prec / grande:%+.5d ", nb);
//     printf("Prec + 0:%0.5d ", nb);
//     printf("Prec + minus:%-.5d ", nb);
//     printf("size:%5d ", nb);
//     printf("size + space:% 5d ", nb);
//     printf("size + plus:%+5d ", nb);
//     printf("size + minus:%-5d ", nb);
//     printf("size + 0:%05d ", nb);
//     printf("size + 0 + plus:%+05d ", nb);
//     printf("size + 0 + plus:%0+5d ", nb);
//     printf("size + 0 + prec:%05.3d ", nb);
//     printf("size + minus + prec:%-5.3d ", nb);
//     printf("size + plus + 0 + prec:%+05.3d ", nb);
//     printf("size + espace + zero + prec:%0 5.3d ", nb);
//     printf("size + espace + zero + prec:% 05.3d ", nb);
//     printf("size + minus + plus + prec:%-+5.3d ", nb);
    
//     dprintf(2, "space% d ", nb);
//     dprintf(2, "plus:%+d ", nb);
//     dprintf(2, "precision:%.5d ", nb);
//     dprintf(2, "space + prec:% .5d ", nb);
//     dprintf(2, "Plus + prec / grande:%+.5d ", nb);
//     dprintf(2, "Prec + 0:%0.5d ", nb);
//     dprintf(2, "Prec + minus:%-.5d ", nb);
//     dprintf(2, "size:%5d ", nb);
//     dprintf(2, "size + space:% 5d ", nb);
//     dprintf(2, "size + plus:%+5d ", nb);
//     dprintf(2, "size + minus:%-5d ", nb);
//     dprintf(2, "size + 0:%05d ", nb);
//     dprintf(2, "size + 0 + plus:%+05d ", nb);
//     dprintf(2, "size + 0 + plus:%0+5d ", nb);
//     dprintf(2, "size + 0 + prec:%05.3d ", nb);
//     dprintf(2, "size + minus + prec:%-5.3d ", nb);
//     dprintf(2, "size + plus + 0 + prec:%+05.3d ", nb);
//     dprintf(2, "size + espace + zero + prec:%0 5.3d ", nb);
//     dprintf(2, "size + espace + zero + prec:% 05.3d ", nb);
//     dprintf(2, "size + minus + plus + prec:%-+5.3d ", nb);
    
    
    
//     ians = read(pipeans[0], ans, 418);
//     icor = read(pipecor[0], cor, 418);
//     if ((nb = close(pipeans[0])) < 0)
//         printf ("error3\n");
//     if ((nb = close(pipecor[0])) < 0)
//         printf ("error4\n");
//     if ((nb = close(pipeans[1])) < 0)
//         printf ("error1\n");
//     if ((nb  = close(pipecor[1])) < 0)
//         printf ("error2\n");
//     ans[ians] = 0;
//     cor[icor] = 0;
    
//     if (strcmp(cor, ans) == 0)
//     {
//         printf("good\n");
//     }
//     else
//         printf ("\nERROR\n");
    
    
//     return (0);
// }





int print_stdout(void)
{

	printf ("NOT dup2\n");
	return (0);
}
int main()
{
	// printf("real:\n");
	// printf("%5.5s", "hello world");
	// printf("\nreal:\n");
	// printf ("len = |%d|",printf("%+10.3d",48));
	// printf ("\nown\n");
	// printf("len = |%d|",ft_printf("%+10.3d", 48));
	// printf("\n\n\n\n\n\n\n");
	// printf("\nreal:\n");
	// printf ("len = |%d|",printf("% h"));
	// printf ("\nown\n");
	// printf("len = |%d|",ft_printf("% h"));
	// printf("\n\n\n\n\n\n\n");
	
	
	
	
	int READING_SIZE = 100000;
	int INTERNAL_FAILURE = 1;
	int		pipeans[2];
	int		pipecor[2];
	int		ians;
	int		icor;
	char	ans[READING_SIZE + 1];
	char	cor[READING_SIZE + 1];

	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);


	int		nb;
	nb = 0;
	ft_printf("space% d ", nb);
	ft_printf("plus:%+d ", nb);
	ft_printf("precision:%.5d ", nb);
	ft_printf("space + prec:% .5d ", nb);
	ft_printf("Plus + prec / grande:%+.5d ", nb);
	ft_printf("Prec + 0:%0.5d ", nb);
	ft_printf("Prec + minus:%-.5d ", nb);
	ft_printf("size:%5d ", nb);
	ft_printf("size + space:% 5d ", nb);
	ft_printf("size + plus:%+5d ", nb);
	ft_printf("size + minus:%-5d ", nb);
	ft_printf("size + 0:%05d ", nb);
	ft_printf("size + 0 + plus:%+05d ", nb);
	ft_printf("size + 0 + plus:%0+5d ", nb);
	ft_printf("size + 0 + prec:%05.3d ", nb);
	ft_printf("size + minus + prec:%-5.3d ", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d ", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d ", nb);
	ft_printf("size + espace + zero + prec:% 05.3d ", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d ", nb);

	dprintf(2, "space% d ", nb);
	dprintf(2, "plus:%+d ", nb);
	dprintf(2, "precision:%.5d ", nb);
	dprintf(2, "space + prec:% .5d ", nb);
	dprintf(2, "Plus + prec / grande:%+.5d ", nb);
	dprintf(2, "Prec + 0:%0.5d ", nb);
	dprintf(2, "Prec + minus:%-.5d ", nb);
	dprintf(2, "size:%5d ", nb);
	dprintf(2, "size + space:% 5d ", nb);
	dprintf(2, "size + plus:%+5d ", nb);
	dprintf(2, "size + minus:%-5d ", nb);
	dprintf(2, "size + 0:%05d ", nb);
	dprintf(2, "size + 0 + plus:%+05d ", nb);
	dprintf(2, "size + 0 + plus:%0+5d ", nb);
	dprintf(2, "size + 0 + prec:%05.3d ", nb);
	dprintf(2, "size + minus + prec:%-5.3d ", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3d ", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3d ", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3d ", nb);
    dprintf(2, "size + minus + plus + prec:%-+5.3d ", nb);



	ians = read(pipeans[0], ans, 418);
	icor = read(pipecor[0], cor, 418);
	if ((nb = close(pipeans[0])) < 0)
		printf ("error3\n");
	if ((nb = close(pipecor[0])) < 0)
		printf ("error4\n");
	if ((nb = close(pipeans[1])) < 0)
		printf ("error1\n");
	if ((nb  = close(pipecor[1])) < 0)
		printf ("error2\n");
	ans[ians] = 0;
	cor[icor] = 0;

	if (ft_strcmp(cor, ans) == 0)
	{
		printf("good\n");
	}
	else 
		printf ("\nERROR\n");

	
	return (0);
}
