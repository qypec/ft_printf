/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:23:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/27 10:34:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		*ft_memint(int *dest, int c, int n)
{
	int i;

	i = 0;
	dest = (int *)ft_memalloc(n);
	while (n--)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}
