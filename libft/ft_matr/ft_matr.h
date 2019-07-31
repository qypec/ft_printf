/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:32:02 by qypec             #+#    #+#             */
/*   Updated: 2019/07/31 15:34:36 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATR_H
# define FT_MATR_H

#include "../includes/libft.h"

char				**ft_matrnew(size_t matr_size, ...);
void				ft_matrmemalloc(size_t  size);
char				**ft_matrdup(char  *first_str,  . . .);
void				ft_matrdel(char  ***matr);

#endif