/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:22:52 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/09 15:50:13 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST
# define FT_LIST

# include "../includes/libft.h"

typedef struct					s_list
{
	char						*content;
	struct s_list				*next;
}								t_list;

void							ft_lstdel(t_list **head);
void							default_lstdel(t_list *list);
t_list							*ft_lstdelone(t_list *head, t_list *dellist);
void							ft_lstadd(t_list **alst, t_list *new);
void							ft_lstpushback(t_list **head, t_list *new);
t_list							*ft_lstnew(const char *content);
int								ft_listsize(t_list *head);

#endif
