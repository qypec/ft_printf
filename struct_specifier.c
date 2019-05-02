/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/02 16:06:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			move_after_lh_bigl(t_spec *spec)
{
	if (spec->big_l == 1 || spec->l == 1 || spec->h == 1)
		return (1);
	if (spec->ll == 1 || spec->hh == 1)
		return (2);
	return (0);
}

int			move_after_digits(char *traverse)
{
	int i;

	i = 0;
	while (ft_isdigit(*traverse) == 1)
	{
		traverse++;
		i++;
	}
	return (i);
}

t_spec		struct_specifier(char *traverse, t_spec *spec)
{
	int i;

	i = 0;
	if (spec->symb == 'k') /* флаг для вывода даты. У нее свои особенности, так что флаги типа ll и прочие ей не нужны */
		return (*spec);
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
	{
		if (traverse[i] == ' ')
		{
			i++;
			spec->space = 1;
		}
		if (traverse[i] == '.') /* если точка, то начинается точность */
		{
			spec = read_digit(traverse + (++i), spec, "precision");
			i += move_after_digits(traverse + i);
		}
		if (is_calculatesymb(traverse[i]) == 1) /* если засек +-0#, заполняет ими структуру */
			spec = read_calculatesymb(traverse[i++], spec);
		if (ft_isdigit(traverse[i]) == 1) /* если точки нет, значит цифры - это просто ширина */
		{
			spec = read_digit(traverse + i, spec, "width");
			i += move_after_digits(traverse + i);
		}
		if (is_lh_bigl(traverse[i]) == 1)
		{
			spec = read_lh_bigl(traverse + i, spec);
			i += move_after_lh_bigl(spec);
		}
	}
	if (traverse[i] != '\0')
		spec->symb = traverse[i];
	return (*spec);
}
