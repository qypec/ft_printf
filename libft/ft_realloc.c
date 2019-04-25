/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:09 by yquaro            #+#    #+#             */
/*   Updated: 2018/12/08 14:29:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t size)
{
	char	*new_str;
	size_t	length;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	length = len + size;
	new_str = (char *)malloc(sizeof(char) * length);
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	while (i < length)
	{
		new_str[i] = '\0';
		i++;
	}
	ft_strdel(&str);
	return (new_str);
}
