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
		addsymb_glbuffer('[');
		number_of_str = ft_itoa(i);
		update_glbuffer(number_of_str);
		ft_strdel(&number_of_str);
		addstr_glbuffer("] ", 2);
		update_glbuffer(matr[i++]);
		if (matr[i] != NULL)
			addsymb_glbuffer('\n');
	}
}
