#include "ft_float.h"
#include "../../includes/header.h"
#define	ROUDING(x)  ((x + 1) >= 10 ? (x) = x + 1 : (x))
#include <stdlib.h>
#include <string.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))


# define FLAG   0
char *ft_rounding(char *number)
{
	int i;
	int j;
	int size;
	char *num = NULL;
	int precision;

	precision = -1;

	i = 0;
	j = 0;
	
	size = strlen(number);
	if (!(num = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	num[size + 1] = '\0';
	num[0] = '0';
	num++;
	/* создаём массив на 1 больше*/
	strcpy(num, number);
	num--;
	
	if (num == NULL)
		return (NULL);
		/*идем до точки  */
	while (num[i] != '.')
		i++;
		/*Смотрим до какого разряда нужно округлить */
	while (i < precision)
		i++;
		/*округляем разряд в большую часть если след разряд больше 4 */
	if (num[i - 1] - 48 > 4 && num[i - 1] - 48 <= 8)
	{
		num[i - 1] = ROUDING(num[i - 1]);
		num[i] = '\0';
	}
	if (num[i - 1] - 48 == 9)
	{
		
	}
	return (num);
}

int main ()
{
	char str1[] = "8.54";
	char str2[] = "3.154";
	char str3[] = "124.11345";
	char str4[] = "124.12345";
	char str5[] = "124.54321";
	char str6[] = "124.67890";
	char *str9;
	// g_->spec = malloc(sizeof(g_spec));
	str9 = ft_rounding(str1);
	printf ("%s", str9);
	return (0);
}