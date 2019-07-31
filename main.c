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
	// char one[] = "3.140000";
	// char two[] = "333333333333333333.14999964745545456";
	// int size_own = 0;
	// int size_real = 0;
		
	// size_own = ft_printf("^.^/%58.32lf^.^", 1065815232,000000);
	// 	printf("\n");
	// size_real =	printf("^.^/%58.32lf^.^", 1065815232,000000);

	// printf ("own = %d\nreal = %d\n", size_own, size_real);
	// ft_printf ("%8lf\n", 0.00);
	// printf ("%8lf\n", 0.00);

	// ft_printf ("%0+lf\n", 0.00);
	// printf ("%0+lf\n", 0.00);

	// ft_printf ("% f\n", 0.00);
	// printf ("% f\n", 0.00);

	// ft_printf ("% #26.8lf\n", 0.00);
	// printf ("% #26.8lf\n", 0.00);

	// ft_printf ("%#0 32lf\n", 0.00);
	// printf ("%#0 32lf\n", 0.00);

	ft_printf ("%#- 42f\n", 0.00);
	printf ("%#- 42f\n", 0.00);

	double		nb;
	nb = -12547.58;

	// ft_printf("test basique:");
	// printf ("\n");
	// dprintf(2, "test basique:");
	// printf ("\n");
	// int size_own = 0;
	// int size_real = 0;
    
	// size_own = ft_printf("% 20f", nb);
	// printf ("\n");
    // size_real= printf("% 20f", nb);
	// printf ("\n");
	// printf ("own = %d\nreal = %d\n",size_own, size_real);
	
	// ft_printf("plus:%+f\n", nb);
	// dprintf(2, "plus:%+f\n", nb);
	
	// ft_printf("hash:%#f\n", nb);
	// dprintf(2, "hash:%#f\n", nb);
	
	// ft_printf("precision:%.2f\n", nb);
	// dprintf(2, "precision:%.2f\n", nb);
	
	// ft_printf("big prec:%.14f\n", nb);
	// dprintf(2, "big prec:%.14f\n", nb);
	

	// ft_printf("precision + hash:%#.0f\n", nb);
	// dprintf(2, "precision + hash:%#.0f\n", nb);
	
	// ft_printf("space + prec:% .5f\n", nb);
	// dprintf(2, "space + prec:% .5f\n", nb);
	
	
	// ft_printf("space + prec + hash:%# .0f\n", nb);
    // dprintf(2, "space + prec + hash:%# .0f\n", nb);
	
	
	// ft_printf("space + prec + hash:% #.0f\n", nb);
    // dprintf(2, "space + prec + hash:% #.0f\n", nb);
	
	// ft_printf("Plus + prec / grande:%+.5f\n", nb);
   	// dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
	
	
	// ft_printf("Plus + prec / petite:%+.0f\n", nb);
	// dprintf(2, "Plus + prec / petite:%+.0f\n", nb);

	
	// ft_printf("Plus + prec + hash:%#+.0f\n", nb);
    // dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);

	
	// ft_printf("Prec + 0:%0.5f\n", nb);
    // dprintf(2, "Prec + 0:%0.5f\n", nb);
	
	
	// ft_printf("Prec + minus:%-.5f\n", nb);
   	// dprintf(2, "Prec + minus:%-.5f\n", nb);
	
	
	// ft_printf("size:%5f\n", nb);
    // dprintf(2, "size:%5f\n", nb);
	
	
	// ft_printf("size + space:% 5f\n", nb);
    // dprintf(2, "size + space:% 5f\n", nb);
	
	// ft_printf("size + plus:%+5f\n", nb);
    // 	dprintf(2, "size + plus:%+5f\n", nb);
	
	// ft_printf("size + space:%# 5f\n", nb);
    // 	dprintf(2, "size + space:%# 5f\n", nb);
	
	// ft_printf("size + plus:%#+5f\n", nb);
    // 	dprintf(2, "size + plus:%#+5f\n", nb);
	
	// ft_printf("size + minus:%-5f\n", nb);
    // 	dprintf(2, "size + minus:%-5f\n", nb);
	
	// ft_printf("size + 0:%05f\n", nb);
    // 	dprintf(2, "size + 0:%05f\n", nb);
	
	// ft_printf("size + 0 + plus:%+05f\n", nb);
    // 	dprintf(2, "size + 0 + plus:%+05f\n", nb);
	
	// ft_printf("size + 0 + plus:%0+5f\n", nb);
    // 	dprintf(2, "size + 0 + plus:%0+5f\n", nb);
	
	// ft_printf("size + 0 + prec:%05.3f\n", nb);
 	// dprintf(2, "size + 0 + prec:%05.3f\n", nb);
 
    // ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
 	// dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);

 
    // ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
 	// dprintf(2, "size + minus + prec + hash:%-#5.0f\n", nb);
 
    // ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
 	// dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
 
    // ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
 	// dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
 
    // ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
 	// dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
 
    // ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
 	// dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
 
    // ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
 	// dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
 
	// int size1 = 0;
	// int size2 = 0;
    // size1 = ft_printf("size + minus + plus + prec:%-+15.3f\n", nb);
 	// size2 = dprintf(2, "size + minus + plus + prec:%-+15.3f\n", nb);
	
	// printf("own = %d\n real  = %d", size1, size2 );
    // ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	// dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	
	return (0)	;
}
