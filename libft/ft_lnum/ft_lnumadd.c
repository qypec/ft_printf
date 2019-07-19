/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnumadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:09:31 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/19 18:21:31 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"

static void			add_result(unsigned char *w, int *j, int a, int *ireg)
{
	if (a == 2)
	{
		w[(*j)--] = '0';
		*ireg = 1;
	}
	else if (a == 3)
	{
		w[(*j)--] = '1';
		*ireg = 1;
	}
	else
	{
		*ireg = 0;
		w[(*j)--] = a + 48;
	}
}

void				ft_lnumadd(unsigned char *w, unsigned char *u, \
							unsigned char *v, int n)
{
	int j;
	int ireg;
	int a;
	int i;

	i = n;
	ireg = 0;
	j = n + 1;
	while (j)
	{
		a = INT(v[i]) + INT(u[i]) + ireg;
		add_result(w, &j, a, &ireg);
		i--;
	}
	w[0] = ireg + 48;
}
