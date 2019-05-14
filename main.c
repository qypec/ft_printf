#include "header.h"


#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//fix parse size + espace + zero + prec:% 05.3d \n\n\n", nb



int main ()
{
	unsigned int  nb = 0;
	char	*str;
	char c = 'W';
	str = "NULL";
	// printf("real:\n");
	// printf("%5.5s\n\n\n", "hello world");
	// printf("\nreal:\n");
	// printf ("len = |%d|\n\n\n",printf("%+10.3d\n\n\n",48));
	// printf ("\nown\n");
	// printf("len = |%d|\n\n\n",ft_printf("%+10.3d\n\n\n", 48));
	// printf("\n\n\n\n\n\n\n");
	// nb = 56432;
	printf("\nreal:\n");
	printf ("len = |%d|",printf("null prec : %.0u\n", nb));
	printf ("\nown\n");
	printf("len = |%d|",ft_printf("null prec : %.0u\n", nb));



	return (0);
}







// int main()
// {
	
// 	int		READING_SIZE = 100000;
// 	int		INTERNAL_FAILURE = 1;
// 	int		pipeans[2];
// 	int		pipecor[2];
// 	int		ians;
// 	int		icor;
// 	char	ans[READING_SIZE + 1];
// 	char	cor[READING_SIZE + 1];
// 	int 	save_out; 

// 	save_out = dup(STDOUT_FILENO);
// 	if (pipe(pipeans) == -1)
// 		return (0);
// 	if (dup2(pipeans[1], 1) == -1)
// 		return (0);
// 	if (pipe(pipecor) == -1)
// 		return (0);
// 	if (dup2(pipecor[1], 2) == -1)
// 		return (0);

// 	int x;
// 	unsigned int		nb;
// 	nb = 0;
// 	ft_printf("null prec : %.0u\n", nb);
// 	nb = 8;
// 	ft_printf("null prec : %.0u\n", nb);
// 	nb = -1234212;
// 	ft_printf("null prec : %.0u\n", nb);
// 	nb = -1;
// 	ft_printf("null prec : %.0u\n", nb);
// 	nb = 12354;
// 	ft_printf("null prec : %.0u\n", nb);

// 	nb = 0;
// 	dprintf(2, "null prec : %.0u\n", nb);
// 	nb = 8;
// 	dprintf(2, "null prec : %.0u\n", nb);
// 	nb = -1234212;
// 	dprintf(2, "null prec : %.0u\n", nb);
// 	nb = -1;
// 	dprintf(2, "null prec : %.0u\n", nb);
// 	nb = 12354;
// 	dprintf(2, "null prec : %.0u\n", nb);




// 	ians = read(pipeans[0], ans, 700);
// 	icor = read(pipecor[0], cor, 700);
// 	if ((x = close(pipeans[0])) < 0)
// 		printf ("error3");
// 	if ((x = close(pipecor[0])) < 0)
// 		printf ("error4\n");
// 	if ((x = close(pipeans[1])) < 0)
// 		printf ("error1\n");
// 	if ((x  = close(pipecor[1])) < 0)
// 		printf ("error2\n");
// 	ans[ians] = 0;
// 	cor[icor] = 0;
// 	dup2(save_out, STDOUT_FILENO);
	
// 	int index = 0;
// 	while (index < ians || index < icor)
// 	{
// 		if (ans[index] != cor[index])
// 			printf ("%c",ans[index]);
// 		index++;
// 	}
// 	index = 0;
// 	printf("\n");
// 	while (index < ians || index < icor)
// 	{
// 		if (ans[index] != cor[index])
// 			printf ("%c",cor[index]);
// 		index++;
// 	}
	
	
	
	
	
	
	
	
	
// 	if (ft_strcmp(cor, ans) == 0)
// 	{
// 		printf("good\n");
// 	}
// 	else 
// 		printf ("\nERROR\n");

	
// 	return (0);
// }
