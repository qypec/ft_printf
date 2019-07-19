/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:58:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/07 06:25:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP
# define FT_MAP

# include "../includes/libft.h"
# include <stdarg.h>

# define DEFAULT_MAP_SIZE 100
# define DEFAULT_HASHFUNC &ft_hashfunc

typedef struct			s_htablist
{
	char				*key;
	void				*value;
	struct s_htablist	*next;
}						ht_list;

typedef struct			s_map
{
	ht_list				**head;
	int					size;
	void				*hashfunc;
}						t_map;

ht_list					*ht_listnew(const char *key, const void *value);
ht_list					*ht_listdelone(ht_list *head, ht_list *dellist);
void					ht_listdel(ht_list **head);

int						ft_hashfunc(const char *str, int size);

t_map					*ft_mapnew(void *hashfunc_ptr, int size);
int						ft_ismapitem(t_map *map, const char *key);
const char				*ft_getvalue(const t_map *map, const char *key);
void					ft_mapinsert(t_map *map, const char *key, \
										const void *value);
void					ft_mapdelone(t_map *map, const char *key);
void					ft_mapdel(t_map **map);
void					ft_putmap(t_map *map);

#endif
