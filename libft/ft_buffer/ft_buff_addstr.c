/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_addstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:17:53 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/30 20:23:47 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

void					ft_buff_addstr(t_buff *buff, char *str)
{
	int					size;

	size = ft_strlen(str);
	while (size >= buff->totalsize - buff->i)
		buff
}
