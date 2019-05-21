/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_something.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:40:01 by oargrave          #+#    #+#             */
/*   Updated: 2019/05/20 17:18:10 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_calculatesymb(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == '.')
		return (1);
	return (0);
}

int		is_lh_bigl(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

int		is_cspdioux_bigx_fegbrk(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
			c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == 'e' ||
			c == 'g' || c == 'b' || c == 'r' || c == 'k' || c == '%' ||
			c == 'U' || c == 'O'  || c == 'S' || c == 'C' || c == 'D')
		return (1);
	else
		return (0);
}
