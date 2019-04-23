#include "header.h"

t_spec	*read_calculatesymb(char с, t_spec *spec)
{
	// if (valid_calculatesymb(*traverse, spec) == 0) /* проверит нет ли уже такого флага в структуре */
		// return (NULL);
	if (с == '#')
		spec->sharp = 1;
	if (с == '0')
		spec->sharp = 1;
	if (с == '+')
		spec->plus = 1;
	if (с == '-')
		spec->minus = 1;
	return (spec);
}

t_spec	*read_lh_bigl(char *traverse, t_spec *spec)
{
	// if (valid_lhL(*traverse, spec) == 0) /* проверит нет ли уже такого флага в структуре */
		// return (NULL);
	if (*traverse == 'L')
	{
		spec->big_l = 1;
		return (spec);
	}
	if (*(traverse + 1) == *traverse)
	{
		// if (*(traverse + 2) == *traverse)
			// return (NULL);
		if (*traverse == 'l')
			spec->ll = 1;
		if (*traverse == 'h')
			spec->hh = 1;
	}
	else
	{
		if (*traverse == 'l')
			spec->l = 1;
		if (*traverse == 'h')
			spec->h = 1;
	}
	return (spec);
}

t_spec	*read_digit(char *traverse, t_spec *spec)
{
	int		num;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (spec->width != 0)
		return (spec);
	while (ft_isdigit(traverse[j]) == 1)
	{
		i++;
		j++;
	}
	str = (char *)ft_memalloc(i + 1);
	str = ft_strncpy(str, traverse, i);
	num = ft_atoi(str);
	spec->width = num;
	ft_strdel(&str);
	return (spec);
}
