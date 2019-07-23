# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/07/23 14:37:54 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
CFLAGS = -g -c
EXECUTABLE = ft_printf


all:
	make -C libft/ all
	make -C src/ all
	make -C lib/ all

clean:
	@make -C lib/ clean

fclean:
	@make -C libft/ fclean
	@rm $(EXECUTABLE)
	@rm $(LIBNAME)

re: fclean all