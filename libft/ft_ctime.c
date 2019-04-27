/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:45:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/27 13:18:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "includes/libft.h"
# define CONDITIONS(yr) (yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0
# define IS_LEAPYEAR(yr) (CONDITIONS(yr)) ? 366 : 365
# define IS_LEAPMONTH(yr) ((IS_LEAPYEAR(yr)) == 366) ? 29 : 28 

static t_ctime		get_year(const time_t *ttime, t_ctime *date)
{
	int day_s;
	int year;
	int day_f;
	// int	per_year[4];
	// int	i;

	// per_year[0] = 365;
	// per_year[1] = 365;
	// per_year[2] = 366;
	// per_year[3] = 365;
	day_s = 0;
	year = 1970 - 1;
	day_f = ((long long int)*ttime) / (60 * 60 * 24);
	// i = 0;
	while (day_s <= day_f)
	{
		// if (i > 3)
			// i = 0;
		// day_s += per_year[i];
		year++;
		day_s += (IS_LEAPYEAR(year));
		// i++;
	}
	date->year_n = year;
	// printf("day_s = %d\n", day_s);
	// printf("day_f = %d\n", day_f);
	date->day_n = IS_LEAPYEAR(year) - (day_s + 1 - day_f) + 2;
	// date->day_n = per_year[i - 1] - (day_s + 1 - day_f) + 2;
	return (*date);
}

static t_ctime		get_weekday(const time_t *ttime, t_ctime *date)
{
	int	day;
	int	weekday;

	day = ((long long int)*ttime) / (60 * 60 * 24);
	weekday = (day % 7);
	if ((weekday + 4) > 7)
		weekday -= 7;
	weekday += 4;
	date->weekday_n = weekday;
	return (*date);
}

static t_ctime		get_month_and_day(const time_t *ttime, t_ctime *date)
{
	int		*arr;
	int		i;
	int		day;
	int		newday;

	i = 0;
	day = 0;
	arr = ft_memint(arr, 31, 12);
	arr[1] = (IS_LEAPMONTH(date->year_n));
	arr[3] = 30;
	arr[5] = 30;
	arr[8] = 30;
	arr[10] = 30;
	date->month_n = 0;
	newday = date->day_n;
	// printf("before: day_n  = %d\n", date->day_n);
	while (day < date->day_n)
	{
		newday -= arr[i];
		day += arr[i];
		(date->month_n)++;
		i++;
	}
	date->day_n = newday + arr[i - 1];
	// printf("newday = %d\ndate->month = %d\n", newday, date->month_n);
	free(arr);
	return (*date);
}

static t_ctime		get_str(t_ctime *date)
{
	if (date->month_n == 1)
		date->month = ft_strdup("Jan");
	if (date->month_n == 2)
		date->month = ft_strdup("Feb");
	if (date->month_n == 3)
		date->month = ft_strdup("Mar");
	if (date->month_n == 4)
		date->month = ft_strdup("Apr");
	if (date->month_n == 5)
		date->month = ft_strdup("May");
	if (date->month_n == 6)
		date->month = ft_strdup("June");
	if (date->month_n == 7)
		date->month = ft_strdup("Jul");
	if (date->month_n == 8)
		date->month = ft_strdup("Aug");
	if (date->month_n == 9)
		date->month = ft_strdup("Sep");
	if (date->month_n == 10)
		date->month = ft_strdup("Oct");
	if (date->month_n == 11)
		date->month = ft_strdup("Nov");
	if (date->month_n == 1)
		date->month = ft_strdup("Dec");
	if (date->weekday_n == 1)
		date->weekday = ft_strdup("Mon");
	else if (date->weekday_n == 2)
		date->weekday = ft_strdup("Tue");
	else if (date->weekday_n == 3)
		date->weekday = ft_strdup("Wed");
	else if (date->weekday_n == 4)
		date->weekday = ft_strdup("Thu");
	else if (date->weekday_n == 5)
		date->weekday = ft_strdup("Fri");
	else if (date->weekday_n == 6)
		date->weekday = ft_strdup("Sat");
	else if (date->weekday_n == 7)
		date->weekday = ft_strdup("Sun");
	date->day = ft_itoa(date->day_n);
	date->year = ft_itoa(date->year_n);
	// printf("\n\n%s\n%s\n%s\n%s\n\n", date->weekday, date->month, date->day, date->year);
	return (*date);
}	

int					ft_ctime(const time_t *ttime)
{
	t_ctime	date;
	long int		day;
	float	res;
	int 	weekday;

	res = 0;
	date = get_year(ttime, &date);
	date = get_weekday(ttime, &date);
	date = get_month_and_day(ttime, &date);
	// printf("year = %d\nday_n = %d\nweekday_n = %d\nmonth_n = %d\n\n", date.year_n, date.day_n, date.weekday_n, date.month_n);
	date = get_str(&date);
	printf("\n\n%s\n%s\n%s\n%s\n\n", date.weekday, date.month, date.day, date.year);
	return (0);
}

// ttime = 63652000; дело в 3:00:00
// ttime = 63672000;
// ttime < 0;

	// day = 1;
	// weekday = 4;
	// while (day <= (long long int)*ttime/ (60 * 60 * 24))
	// {
	// 	day++;
	// 	weekday++;
	// 	if (weekday == 8)
	// 		weekday = 1;
	// }
	// printf("day = %d\n", day);
	// printf("weekday = %d\n", weekday);


int main()
{
	time_t	ttime;

	ttime = time(NULL);
	// ttime = 63652000;
	// ttime = 315360000;
	// ttime = 10801;
	ttime = 0;
	printf("\nctime = %s\n", ctime(&ttime));
	ft_ctime(&ttime);
	return (0);
}
