/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:45:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/25 11:47:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <time.h>
#include "libft.h"

t_ctime		*ft_ctime(const time_t *ttime)
{
	t_ctime		*date;

	// date = nulltermined
	days = putdown_year(ttime, matr);
	int	day_s;
	int	day_f;
	int	year;

	day_s = 0;
	year = 1969;
	day_f = (long long int)*ttime / (60 * 60 * 24);
	// printf("day_f = %d\n", day_f);
	while (day_s < day_f)
	{
		day_s += 365;
		year++;
		if (day_s > day_f)
			break ;
		day_s += 365;
		year++;
		if (day_s > day_f)
			break ;
		day_s += 366;
		year++;
		if (day_s > day_f)
			break ;
		day_s += 365;
		year++;
		if (day_s > day_f)
			break ;
	}
	printf("day = %d\n", day_s - day_f);
	printf("year = %d\n", year);
	return (NULL);
}

int main()
{
	time_t	ttime;

	ttime = time(NULL);
	printf("\nctime = %s\n", ctime(&ttime));
	printf("ft_ctime = %s\n\n", ft_ctime(&ttime));
	return (0);
}
