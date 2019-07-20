/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnum_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:56:39 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/13 21:38:39 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

char					*ft_lnum_to_str(long double dnum)
{
	t_charlnum			*double_ch;
	lnum				extend;
	long double			tmp;
	char				*total_num;
	char				*convetion_num;			

	tmp = dnum;
	extend.ldouble = tmp;
	if ((double_ch = (t_charlnum *)malloc(sizeof(t_charlnum))) == NULL)
		exit(-1);
	double_ch->mantissa = ft_itoa_unbase(extend.components.mantissa, 2);
	double_ch->exponent = ft_itoa_unbase(extend.components.exponent, 2);
	double_ch->sign = extend.components.sign;
	convetion_num = conversion_formula(double_ch);
	ft_lnumdel(&double_ch);
	total_num = bin_to_dec(convetion_num);
	ft_strdel(&convetion_num);
	return (total_num);
}
