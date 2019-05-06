#include "header.h"

static void	nullify_llhh_bigl( )
{
	 g_spec->l = 0;
	 g_spec->h = 0;
	 g_spec->ll = 0;
	 g_spec->hh = 0;
	 g_spec->big_l = 0;
}

void			read_calculatesymb(char c)
{
	if (c == '#')
		 g_spec->sharp = 1;
	if (c == '0')
		 g_spec->zero = 1;
	if (c == '+')
		 g_spec->plus = 1;
	if (c == '-')
		 g_spec->minus = 1;
}

void			read_lh_bigl(char *traverse)
{
	if (*traverse == 'L' &&  g_spec->symb != 'd')
	{
		nullify_llhh_bigl();
		g_spec->big_l = 1;
		return ;
	}
	if (*(traverse + 1) == *traverse)
	{
		if (*traverse == 'l')
		{
			nullify_llhh_bigl();
			g_spec->ll = 1;
		}
		if (*traverse == 'h')
		{
			nullify_llhh_bigl();
			g_spec->hh = 1;
		}
	}
	else
	{
		if (*traverse == 'l')
		{
			nullify_llhh_bigl();
			g_spec->l = 1;
		}
		if (*traverse == 'h')
		{
			nullify_llhh_bigl();
			g_spec->h = 1;
		}
	}
	return ;
}

void			read_digit(char *traverse, const char *flag)
{
	int		num;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_isdigit(*traverse) != 1)
		return ;
	while (ft_isdigit(traverse[j]) == 1)
	{
		i++;
		j++;
	}
	str = (char *)ft_memalloc(i + 1);
	str = ft_strncpy(str, traverse, i);
	num = ft_atoi(str);
	if (ft_strcmp(flag, "width") == 0)
		 g_spec->width = num;
	if (ft_strcmp(flag, "precision") == 0)
		 g_spec->precision = num;
	ft_strdel(&str);
	return ;
}
