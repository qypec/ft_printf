/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnummpsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:17:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/19 18:03:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"
#include <stdio.h>

void				take_a_unit(unsigned char *u, unsigned char *v, int i)
{
	int				a;
	int				j;

	a = INT(u[i]) - INT(v[i]);
	if (a == -1)
	{
		u[i--] = '2';
		while (u[i] != '1')
			u[i--] = '1';
		u[i] = '0';
	}
}

void				ft_lnumsub(unsigned char *w, unsigned char *u, \
							unsigned char *v, int n)
{
	int j;
	int i;

	i = n - 1;
	j = n;
	while (j)
	{
		take_a_unit(u, v, i);
		w[j--] = INT(u[i]) - INT(v[i]) + 48;
		i--;
	}
}

// int main()
// {
// 	unsigned char		*w;
// 	unsigned char		*u;
// 	unsigned char		*v;
// 	int					i;

// 	w = (unsigned char *)malloc(sizeof(unsigned char) * 9);
// 	i = 0;
// 	while (i < 8)
// 		w[i++] = '0';
// 	w[i] = '\0';
// 	u = (unsigned char *)ft_strdup("11001100");
// 	v = (unsigned char *)ft_strdup("10101010");
// 	mpsub(w, u, v, 8);
// 	printf("msub = %s\n", w);
// }