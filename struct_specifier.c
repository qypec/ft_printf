/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/16 16:43:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		is_lhL(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

static int		is_cspdiouxXegbrk(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' /
	 	c == 'u' || c == 'x' || c == 'X' || c == 'e' || c == 'g' || c == 'b' /
	 	c == 'к' || c == 'k' || c == '%')
		return (1);
	else
		return (0);
}

//char	*ft_strwithchr(char c, int num);
char	*ft_strwithchr(char c, int num)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(num + 1);
	while (i < num)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static t_spec	*read_typeflag(char *traverse, t_spec *spec)
{
	// if (valid_lhL(*traverse, spec) == 0) /* проверит нет ли уже такого флага в структуре */
		// return (NULL);
	if (*traverse == 'L')
	{
		spec->typeflag = ft_strwithchr(*traverse, 1);
		return (spec);
	}
	if (*(traverse + 1) == *traverse)
	{
		if (*(traverse + 2) == *travesre)
			return (NULL);
		spec->typeflag = ft_strwithchr(*traverse, 2);
		return (spec);
	}
}

t_spec	*struct_specifier(char *traverse, t_spec *spec)
{
	while (is_cspdiouxXegbrk(*traverse) != 1)
	{
		if (*traverse == ' ')
			spec->space = 1;
		if (is_lhL(*traverse) == 1)
		{
			if ((spec = read_typeflag(traverse, spec)) == NULL)
				return (NULL);
		}
		traverse++;
	}
}