#include "header.h"

static t_spec	*nullify_llhh_bigl(t_spec *spec)
{
	spec->l = 0;
	spec->h = 0;
	spec->ll = 0;
	spec->hh = 0;
	spec->big_l = 0;
	return (spec);
}

t_spec			*read_calculatesymb(char с, t_spec *spec)
{
	if (с == '#')
		spec->sharp = 1;
	if (с == '0')
		spec->zero = 1;
	if (с == '+')
		spec->plus = 1;
	if (с == '-')
		spec->minus = 1;
	if (spec->plus == 1 && spec->minus == 1) /* если и плюс и минус, то плюс нам не нужен */
		spec->plus = 0;
	return (spec);
}

t_spec			*read_lh_bigl(char *traverse, t_spec *spec)
{
	if (*traverse == 'L' && spec->symb != 'd')
	{
		spec = nullify_llhh_bigl(spec);
		spec->big_l = 1;
		return (spec);
	}
	if (*(traverse + 1) == *traverse)
	{
		if (*traverse == 'l')
		{
			spec = nullify_llhh_bigl(spec);
			spec->ll = 1;
		}
		if (*traverse == 'h')
		{
			spec = nullify_llhh_bigl(spec);
			spec->hh = 1;
		}
	}
	else
	{
		if (*traverse == 'l')
		{
			spec = nullify_llhh_bigl(spec);
			spec->l = 1;
		}
		if (*traverse == 'h')
		{
			spec = nullify_llhh_bigl(spec);
			spec->h = 1;
		}
	}
	return (spec);
}

t_spec			*read_digit(char *traverse, t_spec *spec, const char *flag)
{
	int		num;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_isdigit(*traverse) != 1)
		return (spec);
	while (ft_isdigit(traverse[j]) == 1)
	{
		i++;
		j++;
	}
	str = (char *)ft_memalloc(i + 1);
	str = ft_strncpy(str, traverse, i);
	num = ft_atoi(str);
	if (ft_strcmp(flag, "width") == 0)
		spec->width = num;
	if (ft_strcmp(flag, "precision") == 0)
		spec->precision = num;
	ft_strdel(&str);
	return (spec);
}
