# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qypec <qypec@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/08/03 18:18:21 by qypec            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/printf.mk

all:
	@make -C libft/ all
	@make -C src/ all
	@make -C lib/ all
	gcc -g main.c -I includes/ -L. -lftprintf -o ft_printf 

clean:
	@make -C lib/ clean
	@make -C libft/ clean
	@make -C src/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C src/ fclean
	@make -C lib/ fclean
	@rm -f $(NAME)
	@rm -f $(EXECUTABLE)

re: fclean all