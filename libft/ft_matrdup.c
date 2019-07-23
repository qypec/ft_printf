/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:30:01 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/07 06:15:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char					**ft_matrdup(const char **matr)
{
	char				**new;
	int					i;

	i = 0;
	if ((new = (char **)malloc(sizeof(char *) * \
			(ft_matrlen(matr) + 1))) == NULL)
		return (NULL);
	while (matr[i] != NULL)
	{
		new[i] = ft_strdup(matr[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
