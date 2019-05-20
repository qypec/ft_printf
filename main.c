#include "header.h"


#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>


//fix parse size + espace + zero + prec:% 05.3d \n\n\n", nb



int main ()
{
	// double		nb;
	// nb = 125474444444444.58555555555555565565653;
	// char c = 'W';
	// double		nb;
	// nb = -12547.58;
	// char	*str;
	// char c = 'W';
	// str = "NULL";
	// printf("real:\n");
	// printf("%5.5s\n\n\n", "hello world");
	// printf("\nreal:\n");
	// printf ("len = |%d|\n\n\n",printf("%+10.3d\n\n\n",48));
	// printf ("\nown\n");
	// printf("len = |%d|\n\n\n",ft_printf("%+10.3d\n\n\n", 48));
	// printf("\n\n\n\n\n\n\n");
			// printf("\nreal:\n");
			//  int nb = 0;
			// int a = 10;
			printf ("len = |%d|",printf("%.2c", NULL));
			printf ("\nown\n");
			printf("len = |%d|",ft_printf("%.2c", NULL));
	// unsigned long long a = (__LONG_MAX__ *2UL+1UL);
	// printf("%llu", a);
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
	

	
// 	char	*str;
// 	str = "ASD ASDqw ldmj23oi4j32o u89usadjjals j238ujh4 2ojasd  ijo238e 9juasido 8123ue aklnsdk jalhdls";

// 	ft_printf("test basique:%s", str);
// 	ft_printf("precision / zero:%.0s", str);
// 	ft_printf("precision / petite:%.5s", str);
// 	ft_printf("precision / grande:%.15s", str);
// 	ft_printf("prec + minus:%-.5s", str);
// 	ft_printf("size / petite:%5s", str);
// 	ft_printf("size / grande:%15s", str);
// 	ft_printf("Minus + size / petite:%-5s", str);
// 	ft_printf("Minus + size / grande:%-15s", str);
// 	ft_printf("Minus + size + prec:%-15.5s", str);
// 	ft_printf("NULL:%12s", NULL);
// 	ft_printf("NULL:%1s", NULL);
// 	ft_printf("NULL:%-5.6s", NULL);
// 	ft_printf("NULL:%-.8s", NULL);
// 	ft_printf("NULL:%.12s", NULL);
// 	ft_printf("empty:%-.5s", "");
// 	ft_printf("empty:%-1.32s", "");
// 	ft_printf("empty:%1.4s", "");
// 	ft_printf("empty:%23s", "");

// 	dprintf(2, "test basique:%s", str);
// 	dprintf(2, "precision / zero:%.0s", str);
// 	dprintf(2, "precision / petite:%.5s", str);
// 	dprintf(2, "precision / grande:%.15s", str);
// 	dprintf(2, "prec + minus:%-.5s", str);
// 	dprintf(2, "size / petite:%5s", str);
// 	dprintf(2, "size / grande:%15s", str);
// 	dprintf(2, "Minus + size / petite:%-5s", str);
// 	dprintf(2, "Minus + size / grande:%-15s", str);
// 	dprintf(2, "Minus + size + prec:%-15.5s", str);
// 	dprintf(2, "NULL:%12s", NULL);
// 	dprintf(2, "NULL:%1s", NULL);
// 	dprintf(2, "NULL:%-5.6s", NULL);
// 	dprintf(2, "NULL:%-.8s", NULL);
// 	dprintf(2, "NULL:%.12s", NULL);
// 	dprintf(2, "empty:%-.5s", "");
// 	dprintf(2, "empty:%-1.32s", "");
// 	dprintf(2, "empty:%1.4s", "");
// 	dprintf(2, "empty:%23s", "");

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
