/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:31:26 by qypec             #+#    #+#             */
/*   Updated: 2019/07/31 01:32:48 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				print_matrix(va_list arg)
{
	ft_putmatrix(va_arg(arg, char**));
}
