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
	char *result = NULL;
	int precision;

	precision = -1;

	i = 0;
	j = 0;
	size++;
	while (number[size] != '.' || number[size] != '\0')
		size++;
	if (!(result = (char *)malloc(sizeof(char) * (size + precision + 1))))
		return (NULL);
	/* создаём массив на 1 больше*/
	strcpy(result, number);
	result--;
	
	if (result == NULL)
		return (NULL);
		/*идем до точки  */
	while (result[i] != '.')
		i++;
		/*Смотрим до какого разряда нужно округлить */
	while (i < precision)
		i++;
		/*округляем разряд в большую часть если след разряд больше 4 */
	if (result[i - 1] - 48 > 4 && result[i - 1] - 48 <= 8)
	{
		result[i - 1] = ROUDING(result[i - 1]);
		result[i] = '\0';
	}
	if (result[i - 1] - 48 == 9)
	{
		
	}
	return (result);
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