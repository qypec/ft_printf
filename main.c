#include "includes/header.h"
#include "src/ft_lnum/ft_float.h"
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

// int main ()
// {
// 	t_charlnum			*double_ch;

// 	lnum num;
// 	float vaarg = -3.14;
// 	long double tmp = vaarg;
// 	num.ldouble = tmp;
// 	printf("sign = %u\n", num.components.sign);
// 	printf("exponent = %llu\n", num.components.exponent);
// 	printf("mantisa = %llu\n",	num.components.mantissa);
// 	// tmp = pow(2,num.components.exponent - 16383) * (1+(num.components.mantissa / pow(2, 63)));
// 	if ((double_ch = (t_charlnum *)malloc(sizeof(t_charlnum))) == NULL)
// 		exit(-1);
// 	double_ch->mantissa = ft_itoa_unbase(num.components.mantissa, 2);
// 	double_ch->exponent = ft_itoa_unbase(num.components.exponent, 2);
// 	double_ch->sign = num.components.sign;
// 	printf("mantissa_str = %s\n", double_ch->mantissa);
// 	printf("expon_str = %s\n", double_ch->exponent);
// 	printf("sign = %d\n", double_ch->sign);
// 	// printf("total %Lf", tmp);
// 	return (0);
// }


// // static char *ldouble_formula(t_charldouble *double_ch)
// // {

// // }

// void mpadd(char *u, char *v, int n)
// {
// 	int j;
// 	unsigned short ireg = 0;
// 	char *w;
// 	char z = 'A';
// 	w = (char *) malloc(sizeof(char) * 5);
// 	w[n] = '\0';
// 	int i = 0;
// 	for (j = n; j >= 1; j--)
// 	{
// 	ireg = u[j]+v[j]+ HIBYTE(ireg);
// 	w[j+1]=LOBYTE(ireg);
// 	}
// 	w[0] = HIBYTE(ireg);
// 	printf ("%s\n", w);
// // return (w);
// }

// (-1)^sign * 2^(exp - 16383) * (1 + (mantissa / 2^63))
// unsigned char *ft_ldoubleconvert(long double dnum)
// {
// 	ldouble extend;
// 	t_charldouble *double_ch;
// 	char *total_num;
// 	char *calculated;
// 	unsigned char a;

// 	extend.dnum = dnum;
// 	if ((double_ch = (t_charldouble *)malloc(sizeof(t_charldouble))) == NULL)
// 		exit(-1);
// 	double_ch->mantissa = (unsigned char *)\
// 	ft_itoa_unbase(extend.components.mantissa, 2);
// 	double_ch->exponent = (unsigned char *)\
// 	ft_itoa_unbase(extend.components.exponent, 2);
// 	double_ch->sign = extend.components.sign;
// 	printf("mantissa = %s\n", double_ch->mantissa);
// 	printf("exponent = %s\n", double_ch->exponent);
// 	printf("ha = %c\n", (char) (98 & 0xff));
// 	printf("ha = %c\n", (char) (98 » 8 & 0xff));
// 	// calculated = ldouble_formula(double_ch);
// 	// ft_ldoubledel(&double_ch);
// 	// total_num = bin_to_dec(calculated);
// 	// ft_strdel(&calculated);
// 	char str[] = "110";
// 	mpadd(str, str, ft_strlen((char *)str));
// 	return (NULL);
// }

int main()
{
	char one[] = "3.140000";
	char two[] = "3.149999";
	printf("%.3f\n",3.149999);
	return (0)	;
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