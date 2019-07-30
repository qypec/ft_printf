/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:40:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/30 22:21:34 by yquaro           ###   ########.fr       */
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
	ft_strglue(&(buff->str))
}
