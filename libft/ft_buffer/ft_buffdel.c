/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:51:26 by qypec             #+#    #+#             */
/*   Updated: 2019/07/09 14:00:20 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

void					ft_buffdel(t_buff **buff)
{
	ft_strdel(&((*buff)->str));
	(*buff)->i = 0;
	(*buff)->totalsize = 0;
	(*buff)->additional_size = 0;
	free(*buff);
	buff = NULL;
}
