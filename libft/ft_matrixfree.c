/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/01 19:04:23 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_matrixfree(char ***ret)
{
	char	**tmp;
	int		i;

	tmp = *ret;
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
	*ret = tmp;
	return (NULL);
}
