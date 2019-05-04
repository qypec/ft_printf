/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:41:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/04 21:42:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

static void			print_struct(t_cdate *date)
{
	printf("---------------------------------------------\n");
	printf("print struct:\n\n");
	printf("weekday = %s\nweekday_n = %d\n\n", date->weekday, date->weekday_n);
	printf("month = %s\nmonth_n = %d\n\n", date->month, date->month_n);
	printf("day = %s\nday_n = %d\n\n", date->day, date->day_n);
	printf("hour = %s\nhour_n = %d\n\n", date->hour, date->hour_n);
	printf("min = %s\nmin = %d\n\n", date->min, date->min_n);
	printf("sec = %s\nsec_n = %d\n\n", date->sec, date->sec_n);
	printf("year = %s\nyear_n = %d\n\n", date->year, date->year_n);
	printf("---------------------------------------------\n\n");
}

static char 	*whatsparam(char *str, char *buff, t_cdate *date)
{
	if (ft_strcmp(buff, "WDA") == 0)
		str = ft_strglue(str, date->weekday, "\0");
	else if (ft_strcmp(buff, "MNH") == 0)
		str = ft_strglue(str, date->month, "\0");
	else if (ft_strcmp(buff, "DD") == 0)
		str = ft_strglue(str, date->day, "\0");
	else if (ft_strcmp(buff, "hh") == 0)
		str = ft_strglue(str, date->hour, "\0");
	else if (ft_strcmp(buff, "mm") == 0)
		str = ft_strglue(str, date->min, "\0");
	else if (ft_strcmp(buff, "ss") == 0)
		str = ft_strglue(str, date->sec, "\0");
	else if (ft_strcmp(buff, "YYYY") == 0)
		str = ft_strglue(str, date->year, "\0");
	return (str);
}

static char		*fill_str(char *traverse, int size, t_cdate *date)
{
	char	*str;
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	buff = (char *)ft_memalloc(sizeof(char) * 5);
	str = (char *)ft_memalloc(sizeof(char) * size);
	while (traverse[i] != '|' && traverse[i] != '\0')
		i++;
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
	{
		if (traverse[i] == '|')
		{
			i++;
			while (traverse[i] != '|')
			{
				buff[j] = traverse[i];
				i++;
				j++;
			}
			str = whatsparam(str, buff, date);
			buff = ft_memset(buff, 0, 5);
			j = 0;
		}
		if (traverse[i] != '|')
			str = ft_stradd(str, traverse[i]);
		i++;
	}
	ft_strdel(&buff);
	return (str);
}

static int		calculate_size(char *traverse)
{
	int i;
	int	size;

	i = 0;
	size = 0;
	while (traverse[i] != '|' && traverse[i] != '\0')
		i++;
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
	{
		if (traverse[i] == '|')
		{
			i++;
			while (traverse[i] != '|')
			{
				i++;
				size++;
			}
			i++;
		}
		i++;
		size++;
	}
	return (size);
}

int		print_date(char *traverse, va_list arg)
{
	time_t		ttime;
	t_cdate		*date;
	int			size;
	char		*str;

	size = 0;
	// print_strdate(&pattern);
	ttime = va_arg(arg, const time_t);
	date = ft_uctime(&ttime);
	size = calculate_size(traverse);
	// printf("size = %d\n", size);
	str = fill_str(traverse, size, date);
	ft_putstr(str);
	// print_struct(date);
	return (size);
}
