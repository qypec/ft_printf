/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_glbuffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:32:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/31 12:50:45 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		addsymb_glbuffer(char c)
{
	is_it_buffer_overflow(1);
	g_output->str = ft_strnadd(g_output->str, c, g_output->size);
	g_output->size += 1;
}

void		update_glbuffer(char *str)
{
	size_t	size;

	if (str == NULL)
		return ;
	size = ft_strlen(str);
	if (size == 0)
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
