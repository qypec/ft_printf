/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:03:51 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/07 06:45:36 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdio.h>

void					ft_putmap(t_map *map)
{
	int					i;
	int					i_tmp;
	ht_list				**tmp;

	i = 0;
	while (i < map->size)
	{
		if (map->head[i] == NULL)
		{
			i_tmp = i;
			while (map->head[i] == NULL && i < map->size)
				i++;
			i--;
			printf("[%d - %d] : (null)\n", i_tmp, i);
			if (i >= map->size)
				break ;
		}
		else
		{
			printf("[%d] key: |%s| value: |%s|\n", i, map->head[i]->key, \
				(char *)map->head[i]->value);
			tmp = &(map->head[i]);
			while ((*tmp)->next != NULL)
			{
				tmp = &((*tmp)->next);
				printf("-> [%d] key: |%s| value: |%s|\n", i, (*tmp)->key, \
					(char *)(*tmp)->value);
			}
		}
		i++;
	}
	printf("\n");
}
