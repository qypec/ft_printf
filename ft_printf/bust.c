/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bust.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:46:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/05 16:06:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		bust_printf(int errorcode)
{
	if (errorcode == 1)
	{
		ft_puterror("usage:	|*segment of date*| |*segment of date*| ...\
			\n\navailable segments:\n|WDA| for print weekday \
			\n|MNH| for month\n|DD| for day\n|hh| for hours\n|mm| for minutes \
			\n|ss| for seconds\n|YYYY| for year\n \
			\nerror codes:\n|...| is too big segment of date \
			\nx is too small segment of date\n\n");
	}
	// exit(-1);
}