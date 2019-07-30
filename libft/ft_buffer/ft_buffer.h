/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:10:59 by qypec             #+#    #+#             */
/*   Updated: 2019/07/30 20:27:13 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include "../includes/libft.h"

typedef struct			s_buff
{
	char				*str;
	int					i;
	int					totalsize;
	int					additional_size;
}						t_buff;

t_buff					*ft_buffinit(int size);
void					ft_buff_addstr(t_buff *buff, char *str); // добавляет строку в буфер
void					ft_buff_addsymb(t_buff *buff, char symb); // добавляет символ в буфер 
// void					ft_buffreload(t_buff *buff);
void					ft_buffdel(t_buff **buff);


#endif
