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
	// printf ("len = |%d|",printf("%.2f\n", 10.125000000000000001));
	double		nb;
	nb = -12547.599;
	printf ("\nreal\n");
	printf ("len = |%d|",printf("space:% .2f\n", nb));
	printf ("\nown\n");
	printf("len = |%d|",ft_printf("space:% .2f\n", nb));
	
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
// 	x = 0;
// double		nb;
// 	nb = -12547.58;

//     ft_printf("space:% f\n", nb);
//     // ft_printf("plus:%+f\n", nb);
//     // ft_printf("hash:%#f\n", nb);
//     // ft_printf("precision:%.2f\n", nb);
//     // ft_printf("big prec:%.14f\n", nb);
//     // ft_printf("precision + hash:%#.0f\n", nb);
//     // ft_printf("space + prec:% .5f\n", nb);
//     // ft_printf("space + prec + hash:%# .0f\n", nb);
//     // ft_printf("Plus + prec / grande:%+.5f\n", nb);
//     // ft_printf("Plus + prec / petite:%+.0f\n", nb);
//     // ft_printf("Plus + prec + hash:%#+.0f\n", nb);
//     // ft_printf("Prec + 0:%0.5f\n", nb);
//     // ft_printf("Prec + minus:%-.5f\n", nb);
//     // ft_printf("size:%5f\n", nb);
//     // ft_printf("size + space:% 5f\n", nb);
//     // ft_printf("size + plus:%+5f\n", nb);
//     // ft_printf("size + space:%# 5f\n", nb);
//     // ft_printf("size + plus:%#+5f\n", nb);
//     // ft_printf("size + minus:%-5f\n", nb);
//     // ft_printf("size + 0:%05f\n", nb);
//     // ft_printf("size + 0 + plus:%+05f\n", nb);
//     // ft_printf("size + 0 + plus:%0+5f\n", nb);
//     // ft_printf("size + 0 + prec:%05.3f\n", nb);
//     // ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
//     // ft_printf("size + minus + prec:%-5.3f\n", nb);
//     // ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
//     // ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
//     // ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
//     // ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
//     // ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
//     // ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
//     // ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
//     // ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);

// 	dprintf(2, "space:% f\n", nb);
// 	// dprintf(2, "plus:%+f\n", nb);
// 	// dprintf(2, "hash:%#f\n", nb);
// 	// dprintf(2, "precision:%.2f\n", nb);
// 	// dprintf(2, "big prec:%.14f\n", nb);
// 	// dprintf(2, "precision + hash:%#.0f\n", nb);
// 	// dprintf(2, "space + prec:% .5f\n", nb);
// 	// dprintf(2, "space + prec + hash:%# .0f\n", nb);
// 	// dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
// 	// dprintf(2, "Plus + prec / petite:%+.0f\n", nb);
// 	// dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);
// 	// dprintf(2, "Prec + 0:%0.5f\n", nb);
// 	// dprintf(2, "Prec + minus:%-.5f\n", nb);
// 	// dprintf(2, "size:%5f\n", nb);
// 	// dprintf(2, "size + space:% 5f\n", nb);
// 	// dprintf(2, "size + plus:%+5f\n", nb);
// 	// dprintf(2, "size + space:%# 5f\n", nb);
// 	// dprintf(2, "size + plus:%#+5f\n", nb);
// 	// dprintf(2, "size + minus:%-5f\n", nb);
// 	// dprintf(2, "size + 0:%05f\n", nb);
// 	// dprintf(2, "size + 0 + plus:%+05f\n", nb);
// 	// dprintf(2, "size + 0 + plus:%0+5f\n", nb);
// 	// dprintf(2, "size + 0 + prec:%05.3f\n", nb);
// 	// dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);
// 	// dprintf(2, "size + minus + prec:%-5.3f\n", nb);
// 	// dprintf(2, "size + minus + prec + hash:%-#5.0f\n", nb);
// 	// dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
// 	// dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
// 	// dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
// 	// dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
// 	// dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
// 	// dprintf(2, "size + minus + plus + prec:%-+5.3f\n", nb);
// 	// dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	

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