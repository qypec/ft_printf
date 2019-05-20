/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:32:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/20 16:08:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define NO 0
#define YES 1

int					is_badsymb(char c)
{
	if (c == ' ' || c == '.' || c == '0' || c == '+' || c == '-' || \
		c == '#' ||	c == 'h' || c == 'l' || c == 'L' || c == 'z' || \
		c == 'j' || ft_isdigit(c) == 1)
		return (NO);
	return (YES);
}

char				*whichsymb(char *traverse)
{
	if (is_badsymb(*traverse) == YES)
		return (traverse);
	else if (*traverse == ' ')
		traverse = parse_spaces(traverse);
	else if (*traverse == '.')
		traverse = parse_width_or_precision(traverse, PRECISION);
	else if (is_calculatesymb(*traverse) == YES)
		traverse = parse_calculatesymb(traverse);
	else if (ft_isdigit(*traverse) == YES)
		traverse = parse_width_or_precision(traverse, WIDTH);
	else if (is_lh_bigl(*traverse) == YES)
		traverse = parse_lh_bigl(traverse);
	else if (*traverse == 'j')
	{
		g_spec->j = 1;
		traverse = whichsymb(++traverse);
	}
	else if (*traverse == 'z')
	{
		g_spec->z = 1;
		traverse = whichsymb(++traverse);
	}
	return (traverse);
}

char				*struct_spec(char *traverse)
{
	if (is_badsymb(*traverse) == YES)
	{
		if (is_cspdioux_bigx_fegbrk(*traverse) == YES)
		{
			g_spec->symb = *traverse;
			return (traverse + 1);
		}
		return (traverse);
	}
	else
		traverse = whichsymb(traverse);
	if (is_cspdioux_bigx_fegbrk(*traverse) == YES)
	{
		g_spec->symb = *traverse;
		traverse++;
	}
	if (g_spec->minus == 1)
		g_spec->zero = 0;
	return (traverse);
}

char				*parse_spaces(char *traverse)
{
	g_spec->space = 1;
	while (*traverse == ' ')
		traverse++;
	return (whichsymb(traverse));
}
