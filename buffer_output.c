/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:27:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/21 19:40:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		init_bufferoutput(void)
{
	g_output = (t_output *)malloc(sizeof(t_output));
	g_output->buffsize = 50;
	g_output->str = (char *)malloc(sizeof(char) * \
		(g_output->buffsize + 1));
	g_output->size = 0;
	g_output->error = 0;
	g_output->overflow_counter = 1;
}

void		is_it_buffer_overflow(size_t size)
{
	if ((g_output->size + size) > g_output->buffsize)
	{
		(g_output->overflow_counter)++;
		add_memory();
	}
}

void		add_memory(void)
{
	char	*tmp;

	g_output->buffsize *= g_output->overflow_counter;
	tmp = (char *)ft_memalloc(sizeof(char) * g_output->buffsize);
	tmp = ft_memcpy(tmp, g_output->str, g_output->buffsize);
	ft_strdel(&(g_output->str));
	g_output->str = tmp;
}

void		free_bufferoutput(void)
{
	ft_strdel(&(g_output->str));
	free(g_output);
	g_output = NULL;
}
