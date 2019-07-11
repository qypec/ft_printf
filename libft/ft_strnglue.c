/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnglue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:59:24 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/05 19:01:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnglue(char *str, const char *left, const char *right, size_t n)
{
	int i;
	int	counter;

	if (str == NULL || left == NULL || right == NULL)
		return (NULL);
	i = 0;
	counter = n;
	while (left[i] != '\0')
	{
		str[counter] = left[i];
		i++;
		counter++;
	}
	i = 0;
	while (right[i] != '\0')
	{
		str[counter] = right[i];
		i++;
		counter++;
	}
	str[counter] = '\0';
	return (str);
}