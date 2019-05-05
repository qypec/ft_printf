/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:27:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/05 21:17:31 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		init_bufferoutput(void)
{
	gl_output = (t_output *)ft_memalloc(sizeof(t_output));
	gl_output->str = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	gl_output->size = 0;
	gl_output->error = 0;
	gl_output->overflow_counter = 1;
}

void		is_it_buffer_overflow(size_t size)
{
	if ((gl_output->size + size) > (BUFF_SIZE * gl_output->overflow_counter))
	{
		(gl_output->overflow_counter)++;
		add_memory(size);
	}
}

void		add_memory(size_t size)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE * \
			gl_output->overflow_counter));
	tmp = ft_memcpy(tmp, gl_output->str, BUFF_SIZE * \
		(gl_output->overflow_counter - 1));
	ft_strdel(&(gl_output->str));
	gl_output->str = tmp;
}

void		addsymb_glbuffer(char c)
{
	is_it_buffer_overflow(1);
	gl_output->str = ft_strnadd(gl_output->str, c, gl_output->size);
	gl_output->size += 1;
}

void		update_glbuffer(char *str)
{
	size_t size;

	size = ft_strlen(str);
	is_it_buffer_overflow(size);
	gl_output->str = ft_strnglue(gl_output->str, str, "\0", gl_output->size);
}
