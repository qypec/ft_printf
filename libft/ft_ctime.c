/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:45:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/27 08:00:10 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "includes/libft.h"
# define CONDITIONS(yr) (yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0
# define IS_LEAPYEAR(yr) yr = (CONDITIONS(yr)) ? 366 : 365 


// t_ctime		*ft_ctime(const time_t *ttime)
// {
// 	t_ctime		*date;

// 	// date = nulltermined
// 	// days = putdown_year(ttime, matr);
// 	int	day_s;
// 	int	day_f;
// 	int	year;

// 	day_s = 0;
// 	year = 1969;
// 	day_f = (long long int)*ttime / (60 * 60 * 24);
// 	// printf("day_f = %d\n", day_f);
// 	while (day_s < day_f)
// 	{
// 		day_s += 365;
// 		year++;
// 		if (day_s > day_f)
// 			break ;
// 		day_s += 365;
// 		year++;
// 		if (day_s > day_f)
// 			break ;
// 		day_s += 366;
// 		year++;
// 		if (day_s > day_f)
// 			break ;
// 		day_s += 365;
// 		year++;
// 		if (day_s > day_f)
// 			break ;
// 	}
// 	int 	day;
// 	int 	counter;
// 	char	*month;
// 	int		monthday;

// 	counter = 0;
// 	month = (char *)ft_memalloc(4);
// 	day = 365 - (day_s - day_f);
// 	// printf("day = %d\n", day_s - day_f );
// 	printf("year = %d\n", year);
// 	while (counter < day) //надо отследить, високосный год или нет
// 	{
// 		counter += 31; /* January */
// 		month = "Jan";
// 		if (counter > day)
// 			break ;
// 		// if (is_non_leapyear(year) == 1)
// 			counter += 28; /* February */
// 			monthday = 28;
// 		// else
// 			// counter += 29;
// 		month = "Feb";
// 		if (counter > day)
// 			break ;
// 		counter += 31; /* March */
// 		monthday = 31;
// 		month = "Mar";
// 		if (counter > day)
// 			break ;
// 		counter += 30; /* April */
// 		monthday = 30;
// 		month = "Apr";
// 		if (counter > day)
// 			break ;
// 		counter += 31; /* May */
// 		monthday = 31;
// 		month = "May";
// 		if (counter > day)
// 			break ;
// 		counter += 30; /* June */
// 		monthday = 30;
// 		month = "Jun";
// 		if (counter > day)
// 			break ;
// 		counter += 31; /* July */
// 		monthday = 31;
// 		month = "Jul";
// 		if (counter > day)
// 			break ;
// 		counter += 31; /* August */
// 		monthday = 31;
// 		month = "Aug";
// 		if (counter > day)
// 			break ;
// 		counter += 30; /* September */
// 		monthday = 30;
// 		month = "Sep";
// 		if (counter > day)
// 			break ;
// 		counter += 31; /* October */
// 		monthday = 31;
// 		month = "Oct";
// 		if (counter > day)
// 			break ;
// 		counter += 30; /* November */
// 		monthday = 30;
// 		month = "Nov";
// 		if (counter > day)
// 			break ;
// 		counter += 31; /* December */
// 		monthday = 31;
// 		month = "Dec";
// 		if (counter > day)
// 			break ;
// 	}
// 	printf("month = %s\n", month);
// 	printf("day = %d\n", monthday - (counter - day) + 1);
// 	return (NULL);
// }

static t_ctime		get_year(const time_t *ttime, t_ctime *date)
{
	int day_s;
	int year;
	int day_f;
	int	per_year[4];
	int	i;

	per_year[0] = 365;
	per_year[1] = 365;
	per_year[2] = 366;
	per_year[3] = 365;
	day_s = 0;
	year = 1970 - 1;
	day_f = ((long long int)*ttime) / (60 * 60 * 24);
	i = 0;
	while (day_s <= day_f)
	{
		if (i > 3)
			i = 0;
		day_s += per_year[i];
		year++;
		i++;
	}
	date->year_n = year;
	// printf("day_s = %d\n", day_s);
	// printf("day_f = %d\n", day_f);
	date->day_n = per_year[i - 1] - (day_s + 1 - day_f) + 2;
	return (*date);
}

static t_ctime		get_weekday_and_day(const time_t *ttime, t_ctime *date)
{
	int	day;
	int	weekday;

	day = ((long long int)*ttime) / (60 * 60 * 24);
	weekday = (day % 7);
	if ((weekday + 4) > 7)
		weekday -= 7;
	weekday += 4;
	date->weekday_n = weekday;
	printf("weekday = %d\n", weekday);
	return (*date);
}			

int					ft_ctime(const time_t *ttime)
{
	t_ctime	date;
	int	day;
	int	res;
	int weekday;

	res = 0;
	date = get_year(ttime, &date);
	printf("year = %d\nday_n = %d\n\n", date.year_n, date.day_n);

	day = ((long long int)*ttime) / (60 * 60 * 24);

	weekday = (day % 7);
	if ((weekday + 4) > 7)
		weekday -= 7;
	weekday += 4;
	printf("weekday = %d\n", weekday);

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
	// ttime = -10801;
	printf("\nctime = %s\n", ctime(&ttime));
	ft_ctime(&ttime);
	return (0);
}
