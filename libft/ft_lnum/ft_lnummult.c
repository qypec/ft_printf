/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnummult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:47 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/19 18:23:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"

static void			sum(unsigned char *w, unsigned char **matr)
{
	int				i;

	i = 0;
	while (matr[i] != NULL)
	{
		if (matr[i + 1] != NULL)
			ft_lnumadd(w, matr[i], matr[i + 1], ft_strlen(matr[i]))
		i++;
	}
}

void				ft_lnummult(unsigned char *w, unsigned char *u, \
									unsigned char *v, int n)
{
	int				i;
	int				j;
	unsigned char	**matr;

	if ((matr = (unsigned char **)malloc(sizeof(unsigned char *) * \
							(n + 1))) == NULL)
		exit(-1);
	i = 0;
	while (i < n)
	{
		if ((matr[i] = (unsigned char *)malloc(sizeof(unsigned char) * \
							(n + i + 1))) == NULL)
			exit(-1);
		ft_bzero(matr[i], n + i + 1);
	}
	matr[i] = NULL;
	i = 0;
	j = n - 1;
	while (matr[i] != NULL)
	{
		ft_lnumsmult(matr[i], u, INT(v[j]), n);
		i++;
		j--;
	}
	sum(w, matr);
}

int main()
{
	unsigned char		*w;
	unsigned char		*u;
	unsigned char		*v;
	int					i;

	w = (unsigned char *)ft_strdup("00000000000000");
	v = (unsigned char *)ft_strdup("0100010");
	v = (unsigned char *)ft_strdup("0111111");
	ft_lnumult(w, u, v , 7);
	printf("-> %s\n", w);
}