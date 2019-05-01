/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:03:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/01 17:14:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_matrix(char *traverse, va_list arg)
{
	int		size;
	int 	i;
	char	**matr;

	i = 0;
	size = 0;
	matr = va_arg(arg, char **);
	while (matr[i] != NULL)
	{
		ft_putendl(matr[i]);
		size += ft_strlen(matr[i]);
		i++;
	}
	size++;
	return (size);
}