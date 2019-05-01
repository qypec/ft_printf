#include "header.h"

t_date	*read_year(char *traverse, t_date *pattern)
{
	int i;

	while (*traverse != 'k')
	{
		i = 0;
		while (*traverse == 'Y')
		{
			i++;
			traverse++;
		}
		if (i == 2)
		{
			pattern->year4 = 0;
			pattern->year2 = 1;
		}
		else if (i == 4)
		{
			pattern->year2 = 0;
			pattern->year4 = 1;
		}
		if (*traverse != 'Y')
			traverse++;
	}
	return (pattern);
}

t_date	*read_ddwd(char *traverse, t_date *pattern)
{
	int i;

	i = 0;
	while (traverse[i] != 'k')
	{
		if (traverse[i] == 'W' && traverse[i + 1] == 'D')
		{
			pattern->weekday = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (traverse[i] != 'k')
	{
		if (traverse[i] == 'D' && traverse[i + 1] == 'D')
		{
			pattern->day = 1;
			break ;
		}
		i++;
	}
	return (pattern);
}

t_date	*read_month(char *traverse, t_date *pattern)
{
	while (*traverse != 'k')
	{
		if (*traverse == 'M' && *(traverse + 1) == 'M')
		{
			pattern->month = 1;
			break ;
		}
		traverse++;
	}
	return (pattern);
}

t_date	*read_hhmm(char *traverse, t_date *pattern)
{
	int i;

	i = 0;
	while (traverse[i] != 'k')
	{
		if (traverse[i] == 'h' && traverse[i + 1] == 'h')
		{
			pattern->hour = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (traverse[i] != 'k')
	{
		if (traverse[i] == 'm' && traverse[i + 1] == 'm')
		{
			pattern->min = 1;
			break ;
		}
		i++;
	}
	return (pattern);
}

t_date	*read_sec(char *traverse, t_date *pattern)
{
	while (*traverse != 'k')
	{
		if (*traverse == 'S' && *(traverse + 1) == 'S')
		{
			pattern->sec = 1;
			break ;
		}
		traverse++;
	}
	return (pattern);
}
