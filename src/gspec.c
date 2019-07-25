/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gspec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:00:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:39:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 		init_gspec(void)
{
	if (g_spec == NULL)
		if (!(g_spec = malloc(sizeof(t_spec))))
			return ;
	g_spec->symb = (char)48;
	g_spec->width = 0;
	g_spec->space = 0;
	g_spec->sharp = 0;
	g_spec->plus = 0;
	g_spec->minus = 0;
	g_spec->zero = 0;
	g_spec->precision = -1;
	g_spec->big_l = 0;
	g_spec->ll = 0;
	g_spec->l = 0;
	g_spec->j = 0;
	g_spec->hh = 0;
	g_spec->h = 0;
	g_spec->z = 0;
	g_width->zero = 0;
	g_width->space_left = 0;
	g_width->space_right = 0;
	g_width->width = 0;
}

void		gspecfree(void)
{
	g_spec->symb = 0;
	g_spec->width = 0;
	g_spec->space = 0;
	g_spec->sharp = 0;
	g_spec->plus = 0;
	g_spec->minus = 0;
	g_spec->zero = 0;
	g_spec->precision = -1;
	g_spec->big_l = 0;
	g_spec->ll = 0;
	g_spec->l = 0;
	g_spec->j = 0;
	g_spec->hh = 0;
	g_spec->h = 0;
	g_spec->z = 0;
	g_width->zero = 0;
	g_width->space_left = 0;
	g_width->space_right = 0;
	g_width->width = 0;
	free(g_spec);
	g_spec = NULL;
}
