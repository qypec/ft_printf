/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:38:22 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/01 19:04:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_abs( long long int num) // fix denis int -> long long int
{
	if (num == -2147483648)
		return (-1);
	else if (num < 0)
		return (-num);
	else
		return (num);
}
