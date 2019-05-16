/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:23:51 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/06 18:28:38 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_param(char *traverse)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (traverse[i] != '}' && traverse[i] != '\0')
	{
		counter++;
		i++;
		if (counter > 8)
			return (0);
	}
	if (traverse[i] == '\0')
		return (0);
	return (1);
}

char			*take_color(char *traverse)
{
	char	buff[8];
	int		counter;
	int		i;

	i = 1;
	if (check_param(traverse) == 0)
		return (traverse);
	counter = 0;
	ft_bzero(&buff, 8);
	while (traverse[i] != '}')
		buff[counter++] = traverse[i++];
	if (ft_strcmp((const char *)&buff, "reset") == 0)
	{
		addstr_glbuffer(COLOR_RESET, COLOR_SIZE - 1);
		return (traverse + i + 1);
	}
	else if (ft_strcmp((const char *)&buff, "red") == 0)
	{
		addstr_glbuffer(COLOR_RED, COLOR_SIZE);
		return (traverse + i + 1);
	}
	else if (ft_strcmp((const char *)&buff, "blue") == 0)
	{
		addstr_glbuffer(COLOR_BLUE, COLOR_SIZE);
		return (traverse + i + 1);
	}
	else if (ft_strcmp((const char *)&buff, "green") == 0)
	{
		addstr_glbuffer(COLOR_GREEN, COLOR_SIZE);
		return (traverse + i + 1);
	}
	else if (ft_strcmp((const char *)&buff, "yellow") == 0)
	{
		addstr_glbuffer(COLOR_YELLOW, COLOR_SIZE);
		return (traverse + i + 1);
	}
	else if (ft_strcmp((const char *)&buff, "magenta") == 0)
	{
		addstr_glbuffer(COLOR_MAGENTA, COLOR_SIZE);
		return (traverse + i + 1);
	}
	else if (ft_strcmp((const char *)&buff, "cyan") == 0)
	{
		addstr_glbuffer(COLOR_CYAN, COLOR_SIZE);
		return (traverse + i + 1);
	}
	else
		return (traverse);
	return (traverse + i + 1);
}
