/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:24:22 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/07 06:15:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t					ft_matrlen(const char **matr)
{
	size_t				len;

	len = 0;
	while (*matr != NULL)
	{
		len++;
		matr++;
	}
	return (len);
}