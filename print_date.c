#include "header.h"

t_date	*read_year(t_date *pattern)
{
	int i;

	while (*traverse != 'k' && *traverse != '\0')
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
	return (date);
}

char	*parse_date(char *traverse, t_date *pattern)
{
	pattern = read_year(pattern);
	while (*traverse != 'k' && *traverse != '\0')
	{
		if (is_weekday(traverse) == 1)
		{
			traverse += 2;
			pattern->weekday == 1;
		}
		if (is_month(traverse) == 1)
		{
			traverse += 2;
			pattern->month == 1;
		}
		if (is_day(traverse) == 1)
		{
			traverse += 2;
			pattern->day == 1;
		}

	}

}

int		print_date(char *traverse, va_list arg)
{
	const time_t	ttime;
	char			*date;
	t_date			pattern;
	int				size;

	pattern = (t_date){0, 0, 0, 0, (char)48, 0, 0, 0, 0, (char)48};
	pattern = parse_date(traverse, &pattern);
	// ttime = va_arg(arg, const time_t);
	// date = ft_ctime(ttime);
	// date = date_to_format()
	ft_putstr(date);
	size = ft_strlen(date) - 1;
	pattern = (t_date){0, 0, 0, 0, (char)48, 0, 0, 0, 0, (char)48};
	ft_strdel(&date);
	return (size);
}
