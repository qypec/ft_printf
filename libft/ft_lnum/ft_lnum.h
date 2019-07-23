/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:28:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/22 16:09:21 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include "../includes/libft.h"

# define INT(x) (x - 48)

unsigned char			*ft_ldoubleconvert(long double dnum);

void					ft_lnumsub(unsigned char *w, unsigned char *u, \
							unsigned char *v, int n);
void				ft_lnumadd(unsigned char *w, unsigned char *u, \
	unsigned char *v, int n);
void					ft_lnumsmult(unsigned char *w, unsigned char *v, \
										int num, int n);

typedef union
{
	long double		dnum;
	struct
	{
		unsigned long mantissa : 63;
		unsigned long exponent : 15;
		unsigned long sign : 1;
	}				components;
}					ldouble;

typedef struct		s_charldouble
{
	unsigned char	*mantissa;
	unsigned char	*exponent;
	short			sign;
}					t_charldouble;

#endif