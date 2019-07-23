/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnumadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:09:31 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/22 17:12:46 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"
#include <stdio.h>

static unsigned char	add_result(int *j, int a, int *ireg)
{
	if (a == 2)
	{
		*ireg = 1;
		return ('0');
	}
	else if (a == 3)
	{
		*ireg = 1;
		return ('1');
	}
	else
	{
		*ireg = 0;
		return (a + 48);
	}
}

void				ft_lnumadd(unsigned char *w, unsigned char *u, unsigned char *v, int n)
{
	int j;
	int ireg;
	int a;
	int i;
	unsigned char	result[n + 1];

	ireg = 0;
	i = n - 1;
	j = n;
	while (j)
	{
		a = INT(v[i]) + INT(u[i]) + ireg;
		result[j] = add_result(&j, a, &ireg);
		j--;
		i--;
	}
	result[0] = ireg + 48;
	ft_strcpy((char *)w, (const char *)result);
}

// int main()
// {
// 	unsigned char *w;
// 	unsigned char *u;
// 	unsigned char *v;

// 	w = (unsigned char *)malloc(sizeof(unsigned char) * 500);
// 	u = (unsigned char *)ft_strdup("0100");
// 	v = (unsigned char *)ft_strdup("1111");
// 	ft_lnumadd(w, u, v, 4);
// 	printf("%s\n", w);
// }
