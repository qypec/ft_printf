/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:07:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/25 12:30:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)destination;
	while (n--)
		*str++ = (unsigned char)c;
	return (destination);
}
