
#include "../includes/header.h"

void ft_rounding(char *result, int size_result)
{
	int index;
	int transfer;

	transfer = 0;
	index = 0;
	if (result[size_result - 2] >= 53 || (result[size_result - 2] == 53 && result[size_result - 1] >= 54))
			transfer = 1;
	result[size_result - 2] = '\0';
	size_result -= 3;
	while (size_result >= 0)
	{
		if (transfer == 1)
		{
			if (result[size_result] + transfer > 57 && result[size_result] != 46)
			{
				result[size_result] = 48;
				transfer = 1;
			}
			else if (result[size_result] >= 48 && result[size_result] <= 57)
			{
				result[size_result] = result[size_result] + transfer;
				transfer = 0;
			}
			if (result[size_result] == 46 && g_spec->precision == 0)
				result[size_result] = '\0';
		}
		size_result--;
	}
	if (transfer == 1)
			addsymb_glbuffer(49);
}
