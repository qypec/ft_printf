#include "header.h"

void	print_strdate(t_date *pattern) /* на время отладки */
{
	printf("\n");
	printf("year4 = %d\n", pattern->year4);
	printf("year2 = %d\n", pattern->year2);
	printf("weekday = %d\n", pattern->weekday);
	printf("month = %d\n", pattern->month);
	printf("day = %d\n", pattern->day);
	printf("hour = %d\n", pattern->hour);
	printf("min = %d\n", pattern->min);
	printf("sec = %d\n", pattern->sec);
	printf("\n");
}

t_date	parse_date(char *traverse, t_date *pattern)
{
	pattern = read_year(traverse, pattern);
	pattern = read_ddwd(traverse, pattern);
	pattern = read_month(traverse, pattern);
	pattern = read_hhmm(traverse, pattern);
	pattern = read_sec(traverse, pattern);
	return (*pattern);
}

int		print_date(char *traverse, va_list arg)
{
	const time_t	ttime;
	char			*date;
	t_date			pattern;
	int				size;

	pattern = (t_date){0, 0, 0, 0, 0, 0, 0, 0};
	pattern = parse_date(traverse, &pattern);
	print_strdate(&pattern);
	size = 0;
	// ttime = va_arg(arg, const time_t);
	// date = ft_ctime(ttime);
	// date = date_to_format()
	// ft_putstr(date);
	// size = ft_strlen(date) - 1;
	// pattern = (t_date){0, 0, 0, 0, (char)48, 0, 0, 0, 0, (char)48};
	// ft_strdel(&date);
	return (size);
}
