/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_glbuffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:32:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 12:42:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		addsymb_glbuffer(char c)
{
	is_it_buffer_overflow(1);
	g_output->str = ft_strnadd(g_output->str, c, g_output->size);
	g_output->size += 1;
}

void		update_glbuffer(const char *str)
{
	size_t	size;

	if (str == NULL)
		return ;
	if ((size = ft_strlen(str)) == 0)
		return ;
	is_it_buffer_overflow(size);
	ft_strlglue(g_output->size, g_output->str, str, NULL);
	g_output->size += size;
}

void		addstr_glbuffer(char *str, size_t size)
{
	is_it_buffer_overflow(size);
	ft_strlglue(g_output->size, g_output->str, str, NULL);
	g_output->size += size;
}
