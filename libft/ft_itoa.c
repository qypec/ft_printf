/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:30:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/24 21:36:23 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_neg(long long int nn)
{
	long long int			len;
	char					*str;
	long long int			i;
	unsigned long int 			n;

	n = nn;
	n = -n;
	len = ft_numblen(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	i = len;
	str[len + 1] = '\0';
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	str[0] = '-';
	return (str);
}

char			*ft_itoa(long long int n)
{
	long long int		len;
	char	*str;
	long long int		i;

	if (n < 0)
		return (str = ft_itoa_neg(n));
	len = ft_numblen(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = len - 1;
	str[len] = '\0';
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	return (str);
}
