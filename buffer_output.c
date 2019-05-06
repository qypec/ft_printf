/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:27:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/06 12:32:37 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		init_bufferoutput(void)
{
	gl_output = (t_output *)ft_memalloc(sizeof(t_output));
	gl_output->buffsize = 50;
	gl_output->str = (char *)ft_memalloc(sizeof(char) * \
		(gl_output->buffsize + 1));
	gl_output->size = 0;
	gl_output->error = 0;
	gl_output->overflow_counter = 1;
}

void		is_it_buffer_overflow(size_t size)
{
	if ((gl_output->size + size) > gl_output->buffsize)
	{
		(gl_output->overflow_counter)++;
		add_memory(size);
	}
}

void		add_memory(size_t size)
{
	char	*tmp;

	gl_output->buffsize *= gl_output->overflow_counter; /* dynamic buffer */
	tmp = (char *)ft_memalloc(sizeof(char) * gl_output->buffsize);
	tmp = ft_memcpy(tmp, gl_output->str, gl_output->buffsize);
	ft_strdel(&(gl_output->str));
	gl_output->str = tmp;
}

void			free_bufferoutput(void)
{
	ft_strdel(&(gl_output->str));
	free(gl_output);
}
