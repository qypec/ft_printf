/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:57:50 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/25 12:30:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strswap(char **matrix, int first, int second)
{
	char	*tmp;

	tmp = ft_strdup(matrix[first]);
	ft_strdel(&matrix[first]);
	matrix[first] = ft_strdup(matrix[second]);
	ft_strdel(&matrix[second]);
	matrix[second] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (matrix);
}
