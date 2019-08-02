/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:31:26 by qypec             #+#    #+#             */
/*   Updated: 2019/07/31 01:49:38 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				print_matrix(va_list arg)
{
	char			**matr;
	int				i;
	char			*number_of_str;

	matr = va_arg(arg, char**);
	i = 0;
	while (matr[i] != NULL)
	{
		ft_buffaddsymb(g_output, '[');
		number_of_str = ft_itoa(i);
		ft_buffadd(g_output, number_of_str);
		ft_strdel(&number_of_str);
		ft_buffladd(g_output, "] ", 2);
		ft_buffadd(g_output, matr[i++]);
		if (matr[i] != NULL)
			ft_buffaddsymb(g_output, '\n');
	}
}
