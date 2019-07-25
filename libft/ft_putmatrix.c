/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:57:50 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:33:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putmatrix(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_putendl(str[i]);
		i++;
	}
}
