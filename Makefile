# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/07/25 04:09:01 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make_includes/printf.mk

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
	@make -C lib/ fclean
	rm *.o
	rm *.a

re: fclean all