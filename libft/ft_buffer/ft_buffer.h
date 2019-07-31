/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:10:59 by qypec             #+#    #+#             */
/*   Updated: 2019/07/31 13:01:33 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include "../includes/libft.h"

typedef struct			s_buff
{
	char				*str;
	int					i; // номер позиции первого '/0' или размер
	int					totalsize; // размер выделенной памяти
	int					additional_size; // количество добавляемой памяти, когда буфер переполняется
}						t_buff;

t_buff					*ft_buffinit(int size);
void					ft_buffaddsymb(t_buff *buff, char c);
void					ft_buffadd(t_buff *buff, const char *str);
void					ft_buffladd(t_buff *buff, const char *str, int len);
void					ft_buffdel(t_buff **buff);
/*
	Пример: 
		t_buff *buff;

		buff = ft_buffinit(100); // инициализировали буфер с размером 100. В случае переполнения буфера
							размер будет увеличиваться на это же число
		ft_buffadd(buff, "hello world"); // положили строку в буфер
		ft_buffadd(buff, "!"); 			// положили символ в буфер
		ft_buffladd(buff, "example", 7); // положили строку "example" 
					в буфер и указали размер этой строки, чтобы в функции он снова не считался
		ft_buffdel(&buff);
*/


#endif
