/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:27:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/05 17:33:55 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		init_bufferoutput(void)
{
	gl_output = (t_output *)ft_memalloc(sizeof(t_output));
	gl_output->str = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	gl_output->size = 0;
	gl_output->error = 0;
}
