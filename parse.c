#include "header.h"

static char	*move_after_digit(char *traverse)
{
	if (ft_isdigit(*traverse) != 1)
		return (++traverse);
	while (ft_isdigit(*traverse) == 1)
		traverse++;
	return (traverse);
}

void parse_precision(char *traverse)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == '.')
			read_digit(++traverse, PRECISION);
		traverse = move_after_digit(traverse);
	}
	return ;
}

void parse_width(char *traverse)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == '.')
		{
			traverse = move_after_digit(++traverse);
			continue ;
		}
		if (ft_isdigit(*traverse) == 1)
			read_digit(traverse, WIDTH);
		traverse = move_after_digit(traverse);
	}
}

void parse_calculatesymb(char *traverse)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (is_calculatesymb(*traverse) == 1)
			read_calculatesymb(*traverse);
		traverse++;
	}
}

void parse_space(char *traverse)
{
	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
	{
		if (*traverse == ' ')
		{
			 g_spec->space = 1;
			traverse++;
			while (*traverse == ' ')
				traverse++;
		}
		traverse++;
	}
}

// void parse_lh_bigl(char *traverse)
// {
// 	while (is_cspdioux_bigx_fegbrk(*traverse) != 1 && *traverse != '\0')
// 	{
// 		if (is_lh_bigl(*traverse) == 1)
// 		{
// 			read_lh_bigl(traverse);
// 			if ( g_spec->ll == 1 ||  g_spec->hh == 1)
// 				traverse++;
// 		}
// 		traverse++;
// 	}
// }