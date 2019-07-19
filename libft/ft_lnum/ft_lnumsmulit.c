/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnumsmulit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:47:45 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/19 18:20:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"
#include <stdio.h>

void				ft_lnumsmult(unsigned char *w, unsigned char *v, \
										int num, int n)
{
	int				i;

	i = n - 1;
	while (i)
	{
		w[i] = (INT(v[i]) * num) + 48;
		i--;
	}
}

// int main()
// {
// 	unsigned char		*w;
// 	unsigned char		*u;
// 	unsigned char		*v;
// 	int					i;

// 	w = (unsigned char *)ft_strdup("0000000");
// 	v = (unsigned char *)ft_strdup("0100010");
// 	ft_lnumsmult(w, v, 1 , 7);
// 	printf("-> %s\n", w);
// }
