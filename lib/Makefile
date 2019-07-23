# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:13:04 by yquaro            #+#    #+#              #
#    Updated: 2019/07/23 14:36:58 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all:
	@echo \*\*\* Reassemblage
	@ar -x libft.a
	@ar -x printf.a
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@rm __.SYMDEF
	@mv $(NAME) ../$(NAME)
	@echo \*\*\* LIBFTPRINTF COMPLETE!

fclean:
	@rm *.o