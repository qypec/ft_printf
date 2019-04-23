/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/23 17:39:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_spec	struct_specifier(char *traverse, t_spec *spec)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == ' ')
		{
			spec->space = 1;
			while(*traverse == ' ')
				traverse++;
		}
		if (is_calculatesymb(*traverse) == 1)
		{
			spec = read_calculatesymb(*traverse, spec);
			traverse++;
		}
		if (ft_isdigit(*traverse) == 1)
		{
			spec = read_digit(traverse, spec);
			traverse++;
		}
		if (is_lh_bigl(*traverse) == 1)
		{
			spec = read_lh_bigl(traverse, spec);
			if (spec->ll == 1 || spec->hh == 1)
				traverse += 2;
			else
				traverse++;
		}
	}
	if (*traverse == '\0')
	{
		// bust
		exit(-1);
	}
	spec->symb = *traverse;
	return (*spec);
}
