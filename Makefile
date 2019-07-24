# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/07/24 21:27:18 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -c
LIBNAME = libftprintf.a
# PRINTF_H =	-I includes/

all:
	@make -C libft/ all
	@make -C src/ all
	@make -C lib/ all
	gcc -g main.c -L. -lftprintf -o ft_printf

clean:
	@make -C lib/ clean
	@make -C libft/ clean
	@make -C src/ clean

fclean:
	@make -C libft/ fclean
	@make -C src/ fclean
	@make -C lib/ clean
	rm $(LIBNAME)

re: fclean all