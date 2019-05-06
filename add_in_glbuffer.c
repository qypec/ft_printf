/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_glbuffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:32:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/06 13:10:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		addsymb_glbuffer(char c)
{
	is_it_buffer_overflow(1);
	g_output->str = ft_strnadd(g_output->str, c, g_output->size);
	g_output->size += 1;
}

void		update_glbuffer(char *str)
{
	size_t size;

	size = ft_strlen(str);
	is_it_buffer_overflow(size);
	g_output->str = ft_strnglue(g_output->str, str, "\0", g_output->size);
	g_output->size += size;
}

void		addstr_glbuffer(char *str, size_t size)
{
	is_it_buffer_overflow(size);
	g_output->str = ft_strnglue(g_output->str, str, "\0", g_output->size);
	g_output->size += size;
}
