/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnummult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:47 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/22 17:39:08 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"
#include <stdio.h>

static void				sum(unsigned char *w, unsigned char **matr, int n)
{
	int					i;

	i = 0;
	while (matr[i] != NULL)
	{
		tmp = ft_lnumadd(w, w, matr[i], n);
		
		i++;
	}
}

static void				*smult(unsigned char *u, int num, int position, int n)
{
	unsigned char		*w;

	if ((w = (unsigned char *)malloc(sizeof(unsigned char) * (n * 2))) == NULL)
		exit(-1);
	ft_bzero(w, (n * 2) - 1);
	while (--n >= 0)
		w[--position] = INT(u[n]) * num + 48;
	return (w);
}

void				ft_lnummult(unsigned char *w, unsigned char *u, \
									unsigned char *v, int n)
{
	int				i;
	int				j;
	unsigned char	**matr;

	if ((matr = (unsigned char **)malloc(sizeof(unsigned char *) * (n + 1))) == NULL)
		exit(-1);
	i = 0;
	j = n - 1;
	while (j >= 0)
	{
		matr[i] = smult(u, INT(v[j]), (n * 2) - i - 1, n);
		j--;
		i++;
	}
	matr[i] = NULL;
	sum(w, matr, n * 2 - 1);
	ft_matrixfree((char ***)&matr);
}

int main()
{
	unsigned char		*w;
	unsigned char		*u;
	unsigned char		*v;
	int					i;
	
	w = (unsigned char *)malloc(sizeof(unsigned char) * 500);
	ft_bzero(w, 499);
	u = (unsigned char *)ft_strdup("0100");
	v = (unsigned char *)ft_strdup("1111");
	ft_lnummult(w, u, v , 4);
	printf("-> %s\n", w);
}