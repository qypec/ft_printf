/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:40:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/30 23:14:30 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

void					ft_buffadd(t_buff *buff, const char *str)
{
	int					size_of_new_str;
	int					remaining_size;

	if (str == NULL)
		return ;
	remaining_size = buff->totalsize - buff->i;
	size_of_new_str = ft_strlen(str);
	if (remaining_size <= size_of_new_str)
	{
		buff->totalsize += size_of_new_str + buff->additional_size;
		if ((buff->str = ft_realloc(buff->str, buff->totalsize)) == NULL)
			exit(1);
	}
	ft_strlglue(buff->i, buff->str, str, NULL);
	buff->i += size_of_new_str;
}

void					ft_buffladd(t_buff *buff, const char *str, int len)
{
	int					size_of_new_str;
	int					remaining_size;

	if (str == NULL)
		return ;
	remaining_size = buff->totalsize - buff->i;
	size_of_new_str = len;
	if (remaining_size <= size_of_new_str)
	{
		buff->totalsize += size_of_new_str + buff->additional_size;
		if ((buff->str = ft_realloc(buff->str, buff->totalsize)) == NULL)
			exit(1);
	}
	ft_strlglue(buff->i, buff->str, str, NULL);
	buff->i += size_of_new_str;
}
