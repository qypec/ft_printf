# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 19:07:01 by yquaro            #+#    #+#              #
#    Updated: 2019/05/17 16:29:48 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C ft_printf/ re
	gcc ft_printf/main.c -L. -lftprintf -o ft_out

clean:
	make -C ft_printf/ clean
	make -C speedtest/ clean
	rm -f libftprintf.a

fclean: clean
	make -C ft_printf/ fclean
	rm -f ft_out

re: fclean all

speedtest: all
	mv libftprintf.a speedtest/libftprintf.a
	rm ft_out
	make -C speedtest/ all

speedtest_re: fclean speedtest

run_speedtest:
	make -C speedtest/ run