/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:11:41 by qypec             #+#    #+#             */
/*   Updated: 2019/07/09 13:22:04 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

t_buff					*ft_buffinit(int size)
{
	t_buff				*buff;

	if ((buff = (t_buff *)malloc(sizeof(t_buff))) == NULL)
		exit(-1);
	buff->additional_size = size;
	buff->totalsize = size;
	if ((buff->str = (char *)ft_memalloc(sizeof(char) * buff->totalsize)) == NULL)
		exit(-1);
	buff->i = 0;
	return (buff);
}
