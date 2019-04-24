#include "header.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

 int        ft_itoa_help(int tmp, int base, int flag)
 {
     int                  size; 

     size = 0;
     while (tmp /= base)
		size++;
	size = size + flag + 1;

     return(size);
    
 }

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	int		flag;
	int		tmp;
	
    flag = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
    size = ft_itoa_help(tmp, base, flag);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
        return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = TAB[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}