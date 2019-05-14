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
	printf("\nreal:\n");
	printf ("len = |%d|\n\n\n",printf("% h"));
	printf ("\nown\n");
	printf("len = |%d|\n\n\n",ft_printf("% h"));
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

// 	int		nb;

// 	nb = 0;
// 	char	*str;
// 	str = "NULL";

// 	ft_printf("test basique:%s\n", str);
// 	ft_printf("precision / zero:%.0s\n", str);
// 	ft_printf("precision / petite:%.5s\n", str);
// 	ft_printf("precision / grande:%.15s\n", str);
// 	ft_printf("prec + minus:%-.5s\n", str);
// 	ft_printf("size / petite:%5s\n", str);
// 	ft_printf("size / grande:%15s\n", str);
// 	ft_printf("Minus + size / petite:%-5s\n", str);
// 	ft_printf("Minus + size / grande:%-15s\n", str);
// 	ft_printf("Minus + size + prec:%-15.5s\n", str);
// 	ft_printf("NULL:%12s\n", NULL);
// 	ft_printf("NULL:%1s\n", NULL);
// 	ft_printf("NULL:%-5.6s\n", NULL);
// 	ft_printf("NULL:%-.8s\n", NULL);
// 	ft_printf("NULL:%.12s\n", NULL);
// 	ft_printf("empty:%-.5s\n", "");
// 	ft_printf("empty:%-1.32s\n", "");
// 	ft_printf("empty:%1.4s\n", "");
// 	ft_printf("empty:%23s\n", "");

// 	dprintf(2, "test basique:%s\n", str);
// 	dprintf(2, "precision / zero:%.0s\n", str);
// 	dprintf(2, "precision / petite:%.5s\n", str);
// 	dprintf(2, "precision / grande:%.15s\n", str);
// 	dprintf(2, "prec + minus:%-.5s\n", str);
// 	dprintf(2, "size / petite:%5s\n", str);
// 	dprintf(2, "size / grande:%15s\n", str);
// 	dprintf(2, "Minus + size / petite:%-5s\n", str);
// 	dprintf(2, "Minus + size / grande:%-15s\n", str);
// 	dprintf(2, "Minus + size + prec:%-15.5s\n", str);
// 	dprintf(2, "NULL:%12s\n", NULL);
// 	dprintf(2, "NULL:%1s\n", NULL);
// 	dprintf(2, "NULL:%-5.6s\n", NULL);
// 	dprintf(2, "NULL:%-.8s\n", NULL);
// 	dprintf(2, "NULL:%.12s\n", NULL);
// 	dprintf(2, "empty:%-.5s\n", "");
// 	dprintf(2, "empty:%-1.32s\n", "");
// 	dprintf(2, "empty:%1.4s\n", "");
// 	dprintf(2, "empty:%23s\n", "");



// 	ians = read(pipeans[0], ans, 700);
// 	icor = read(pipecor[0], cor, 700);
// 	if ((nb = close(pipeans[0])) < 0)
// 		printf ("error3");
// 	if ((nb = close(pipecor[0])) < 0)
// 		printf ("error4\n");
// 	if ((nb = close(pipeans[1])) < 0)
// 		printf ("error1\n");
// 	if ((nb  = close(pipecor[1])) < 0)
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
