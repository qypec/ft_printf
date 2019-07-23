/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldoubleconvert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:59:52 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/22 16:12:23 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lnum.h"
#include <stdio.h>

static char				*ldouble_formula(t_charldouble *double_ch)
{
	unsigned char		*calculated;

	if ((calculated = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 500)) == NULL)
		exit(-1);
	
}

// (-1)^sign * 2^(exp - 16383) * (1 + (mantissa / 2^63))
unsigned char					*ft_ldoubleconvert(long double dnum)
{
	t_charldouble		*double_ch;
	ldouble				extend;
	char				*total_num;
	char				*calculated;
	unsigned char a;

	extend.dnum = dnum;
	if ((double_ch = (t_charldouble *)malloc(sizeof(t_charldouble))) == NULL)
		exit(-1);
	double_ch->mantissa = (unsigned char *)\
						ft_itoa_unbase(extend.components.mantissa, 2);
	double_ch->exponent = (unsigned char *)\
						ft_itoa_unbase(extend.components.exponent, 2);
	double_ch->sign = extend.components.sign;
	printf("mantissa = %s\n", double_ch->mantissa);
	printf("exponent = %s\n", double_ch->exponent);
	// calculated = ldouble_formula(double_ch);
	// ft_ldoubledel(&double_ch);
	// total_num = bin_to_dec(calculated);
	// ft_strdel(&calculated);
	return (NULL);
	}

int main()
{
	printf("total = |%s|\n", ft_ldoubleconvert(3.14));
	return (0);
}