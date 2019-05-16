/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:55:46 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/01 19:04:27 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_pow(int num, int power)
{
	int tot;

	tot = num;
	if (power < 0)
		return (-1);
	if (power == 0)
		return (1);
	if (power == 1)
		return (num);
	while (power-- != 1)
		tot *= num;
	return (tot);
}