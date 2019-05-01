#include "header.h"

static char	*move_after_digit(char *traverse)
{
	if (ft_isdigit(*traverse) != 1)
		return (++traverse);
	while (ft_isdigit(*traverse) == 1)
		traverse++;
	return (traverse);
}

t_spec		*parse_precision(char *traverse, t_spec *spec)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == '.')
			spec = read_digit(++traverse, spec, "precision");
		traverse = move_after_digit(traverse);
	}
	return (spec);
}

t_spec		*parse_width(char *traverse, t_spec *spec)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == '.')
		{
			traverse = move_after_digit(++traverse);
			continue ;
		}
		if (ft_isdigit(*traverse) == 1)
			spec = read_digit(traverse, spec, "width");
		traverse = move_after_digit(traverse);
	}
	return (spec);
}

t_spec		*parse_calculatesymb(char *traverse, t_spec *spec)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (is_calculatesymb(*traverse) == 1)
			spec = read_calculatesymb(*traverse, spec);
		traverse++;
	}
	return (spec);
}

t_spec		*parse_space(char *traverse, t_spec *spec)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == ' ')
		{
			spec->space = 1;
			traverse++;
			while (*traverse == ' ')
				traverse++;
		}
		traverse++;
	}
	return (spec);
}

t_spec		*parse_lh_bigl(char *traverse, t_spec *spec)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (is_lh_bigl(*traverse) == 1)
		{
			spec = read_lh_bigl(traverse, spec);
			if (spec->ll == 1 || spec->hh == 1)
				traverse++;
		}
		traverse++;
	}
	return (spec);
}