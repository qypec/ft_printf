/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:09:33 by oargrave          #+#    #+#             */
/*   Updated: 2019/07/30 20:10:31 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_part(t_part *part)
{	
	if ((part = (t_part *)malloc(sizeof(t_part))) == NULL)
		exit(-1);
	part->first = NULL;
	part->middle = NULL;
	part->last = NULL;
	part->is_neg = 0;
}