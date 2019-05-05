/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:59:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/04 19:32:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

static char			*glue_str(t_cdate *date, char *str)
{
	str = ft_strglue(str, date->weekday, " ");
	if (ft_strlen(date->day) == 1)
		str = ft_strglue(str, date->month, "  ");
	else
		str = ft_strglue(str, date->month, " ");
	str = ft_strglue(str, date->day, " ");
	str = ft_strglue(str, date->hour, ":");
	str = ft_strglue(str, date->min, ":");
	str = ft_strglue(str, date->sec, " ");
	str = ft_strglue(str, date->year, "\0");
	return (str);
}

static char			*like_original_ctime(t_cdate *date)
{
	char	*str;
	int		spaces;
	int		len;

	if (ft_strlen(date->day) == 2)
		spaces = NUMBER_OF_SPACES;
	else
		spaces = NUMBER_OF_SPACES - 1;
	len = 3 + 3 + ft_strlen(date->day) + ft_strlen(date->hour) + \
		ft_strlen(date->min) + ft_strlen(date->sec) + \
		ft_strlen(date->year) + 1 + spaces;
	str = (char *)ft_memalloc(sizeof(char) * len);
	str[len] = '\0';
	str = glue_str(date, str);
	return (str);
}

char				*ft_ctime(const time_t *ttime)
{
	t_cdate		*date;
	char		*str;

	if (*ttime < 0)
	{
		ft_puterror("ERROR: ft_ctime does not work with negative numbers\n");
		exit(-1);
	}
	date = ft_uctime(ttime);
	str = like_original_ctime(date);
	free_uctime(date);
	return (str);
}
