/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/24 20:19:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_spec		struct_specifier(char *traverse, t_spec *spec)
{
	int i;

	i = 0;
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
		i++;
	if (traverse[i] != '\0')
		spec->symb = traverse[i];
	if (spec->symb == 'k')
		return (spec);
	spec = parse_space(traverse, spec);
	spec = parse_calculatesymb(traverse, spec);
	spec = parse_width(traverse, spec);
	spec = parse_precision(traverse, spec);
	spec = parse_lh_bigl(traverse, spec);
	return (*spec);
}
