/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/14 19:46:26 by yquaro           ###   ########.fr       */
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

static int	read_some_flags(char *traverse, int i)
{
	if (ft_isdigit(traverse[i]) == 1) /* если точки нет, значит цифры - это просто ширина */
		i = read_width_or_precision(traverse, i, WIDTH);
	if (traverse[i] == 'j')
		g_spec->j = 1;
	if (traverse[i] == 'z')
		g_spec->z = 1;
	if (is_lh_bigl(traverse[i]) == 1)
		i = read_lh_bigl(traverse + i, i);
	if (is_nonsymb(traverse[i]) == 1)
		i++;
	return (i);
}

int				read_spaces(char *traverse, int i)
{
	g_spec->space = 1;
	while (traverse[i] == ' ')
		i++;
	return (i);
}

void		struct_specifier(char *traverse)
{
	int i;

	i = 0;
	g_spec->symb = find_symb(traverse);
	if (g_spec->symb == 'k') /* флаг для вывода даты. У нее свои особенности, так что флаги типа ll и прочие ей не нужны */
		return ;
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
	{
		if (traverse[i] == ' ')
			i = read_spaces(traverse, i);
		if (traverse[i] == '.') /* если точка, то начинается точность */
			i = read_width_or_precision(traverse, i, PRECISION);
		if (is_calculatesymb(traverse[i]) == 1) /* если засек +-0#, заполняет ими структуру */
		{
			read_calculatesymb(traverse[i++]);
			continue ;
		}
		i = read_some_flags(traverse, i);
	}
	if (g_spec->minus == 1)
		g_spec->zero = 0;
}
