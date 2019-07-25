/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:41:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 10:57:09 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char 	*whatsparam(char *str, char *buff, t_cdate *date)
{
	int len;

	len = 0;
	if (ft_strcmp(buff, "WDA") == 0)
		ft_strglue(&str, date->weekday, "\0");
	else if (ft_strcmp(buff, "MNH") == 0)
		ft_strglue(&str, date->month, "\0");
	else if (ft_strcmp(buff, "DD") == 0)
		ft_strglue(&str, date->day, "\0");
	else if (ft_strcmp(buff, "hh") == 0)
		ft_strglue(&str, date->hour, "\0");
	else if (ft_strcmp(buff, "mm") == 0)
		ft_strglue(&str, date->min, "\0");
	else if (ft_strcmp(buff, "ss") == 0)
		ft_strglue(&str, date->sec, "\0");
	else if (ft_strcmp(buff, "YYYY") == 0)
		ft_strglue(&str, date->year, "\0");
	else
	{
		len = ft_strlen(buff);
		while (len--)
			ft_strglue(&str, "x", "\0");
	}
	return (str);
}

static char		*read_segment_of_date(char *traverse, char *str, t_cdate *date)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char *)ft_memalloc(sizeof(char) * 6);
	while (traverse[i] != '|' && traverse[i] != '\0')
	{
		buff[i] = traverse[i];
		i++;
		if (i >= 5)
		{
			buff = ft_memcpy(buff, "|...|", 6);
			ft_strglue(&str, buff, "\0");
			ft_strdel(&buff);
			bust_printf(1);
			return (str);
		}
	}
	str = whatsparam(str, buff, date);
	ft_strdel(&buff);
	return (str);
}

static char		*fill_str(char *traverse, int size, t_cdate *date)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)ft_memalloc(sizeof(char) * (size + RESERVE));
	while (traverse[i] != '|' && traverse[i] != '\0')
		i++;
	while (is_cspdioux_bigx_fegbrk(traverse[i]) != 1 && traverse[i] != '\0')
	{
		if (traverse[i] == '|')
		{
			str = read_segment_of_date(traverse + (++i), str, date);
			while (traverse[i] != '|' && traverse[i] != '\0')
				i++;
		}
		if (traverse[i] != '|')
			str = ft_stradd(str, traverse[i]);
		i++;
	}
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
			while (traverse[i] != '|' && traverse[i] != '\0')
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

void			print_date(char *traverse, va_list arg)
{
	time_t		ttime;
	t_cdate		*date;
	int			size;
	char		*str;

	size = 0;
	ttime = va_arg(arg, const time_t);
	date = ft_uctime(&ttime);
	if ((size = calculate_size(traverse)) > 256)
	{
		ft_putstr("ERROR: too big argument with flag %k");
		free_uctime(date);
		return ;
	}
	str = fill_str(traverse, size, date);
	addstr_glbuffer(str, size);
	ft_strdel(&str);
	free_uctime(date);
}
