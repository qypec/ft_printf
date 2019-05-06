/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/06 12:07:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

const char	find_symb(char *traverse)
{
	int i;

	i = 0;
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
	{
		if (traverse[i] == '|')
		{
			i++;
			while (traverse[i] != '|')
				i++;
		}
		i++;
	}
	if (traverse[i] == '\0')
		return ((char)48);
	return (traverse[i]);
}

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

int			is_nonsymb(char c)
{
	if (is_calculatesymb(c) == 1 || is_lh_bigl(c) == 1)
		return (0);
	if (is_cspdioux_bigx_fegbrk(c) == 1 || c == '.' || c == ' ')
		return (0);
	return (1);
}

t_spec		struct_specifier(char *traverse, t_spec *spec)
{
	int i;

	i = 0;
	spec->symb = find_symb(traverse);
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
		{
			spec = read_calculatesymb(traverse[i++], spec);
			continue ;
		}
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
		if (is_nonsymb(traverse[i]) == 1)
			i++;
	}
	if (traverse[i] != '\0')
		spec->symb = traverse[i];
	if (spec->minus == 1)
		spec->zero = 0;
	if (spec->zero == 1)
		spec->space = 0;
	return (*spec);
}
