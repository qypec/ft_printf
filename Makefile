# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/07/23 19:27:56 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
CFLAGS = -g -c
LIBNAME = libftprintf.a

all:
	@make -C libft/ all
	@make -C src/ all
	@make -C lib/ all

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