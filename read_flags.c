#include "header.h"

static void	nullify_llhh_bigl(int flag)
{
	g_spec->l = 0;
	g_spec->h = 0;
	g_spec->ll = 0;
	g_spec->hh = 0;
	g_spec->big_l = 0;
	if (flag == 1)
		g_spec->l = 1;
	if (flag == 2)
		g_spec->ll = 1;
	if (flag == 3)
		g_spec->big_l = 1;
	if (flag == 4)
		g_spec->h = 1;
	if (flag == 5)
		g_spec->hh = 1;
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

static int			move_after_lh_bigl(void)
{
	if (g_spec->big_l == 1 ||  g_spec->l == 1 ||  g_spec->h == 1)
		return (1);
	if (g_spec->ll == 1 ||  g_spec->hh == 1)
		return (2);
	return (0);
}

int			read_lh_bigl(char *traverse, int i)
{
	if (*traverse == 'L' &&  g_spec->symb != 'd')
	{
		nullify_llhh_bigl(3);
		i++;
		return (i);
	}
	if (*(traverse + 1) == *traverse)
	{
		if (*traverse == 'l')
			nullify_llhh_bigl(2);
		if (*traverse == 'h')
			nullify_llhh_bigl(5);
	}
	else
	{
		if (*traverse == 'l')
			nullify_llhh_bigl(1);
		if (*traverse == 'h')
			nullify_llhh_bigl(4);
	}
	i += move_after_lh_bigl();
	return (i);
}

int				read_spaces(char *traverse, int i)
{
	g_spec->space = 1;
	while (traverse[i] == ' ')
		i++;
	return (i);
}

void			read_digit(char *traverse, const int flag)
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
	if (flag == WIDTH)
		 g_spec->width = num;
	if (flag == PRECISION)
		 g_spec->precision = num;
	ft_strdel(&str);
	return ;
}

int				read_precision(char *traverse, int i)
{
	g_spec->precision = 0;
	read_digit(traverse + (++i), PRECISION);
	i += move_after_digits(traverse + i);
	return (i);
}
