/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:30:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 22:15:24 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static void				default_del(ht_list *list)
{
	list->next = NULL;
	// ft_strdel(&(list->key));
	// ft_strdel((char **)&(list->value));
	list->key = NULL;
	list->value = NULL;
	free(list);
	list = NULL;
}

ht_list					*ht_listdelone(ht_list *head, ht_list *dellist)
{
	ht_list				*tmp;
	ht_list				*lst;

	if (dellist == NULL)
		return (NULL);
	tmp = head;
	lst = dellist;
	if (tmp == lst)
	{
		head = head->next;
		default_del(lst);
		lst = head;
		return (lst);
	}
	if (tmp->next != NULL)
	{
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	default_del(lst);
	return (head);
}

void					ht_listdel(ht_list **head)
{
	ht_list				*tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		if ((*head = ht_listdelone(*head, tmp)) == NULL)
			return ;
		tmp = (*head);
	}
	default_del(*head);
}

ht_list					*ht_listnew(const char *key, const void *value)
{
	ht_list				*list;

	if ((list = (ht_list *)malloc(sizeof(ht_list))) == NULL)
		return (NULL);
	list->key = (char *)key;
	list->value = (void *)value;
	list->next = NULL;
	return (list);
}
