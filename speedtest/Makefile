# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 20:05:07 by yquaro            #+#    #+#              #
#    Updated: 2019/05/17 12:45:35 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCE = 
# OBJS = *.c
OBJDIR = .obj
NAME = libspeedtest.a

all:
# 	gcc -c $(SOURCE)
# 	mkdir $(OBJDIR)
# 	mv $(OBJS) $(OBJDIR)
# 	ar rc $(NAME) $(OBJDIR)/$(OBJS)
# 	ranlib $(NAME)
# 	gcc main.c -L. -lftprintf -lspeedtest -o speed_out
	gcc -g main.c -L. -lftprintf -o speed_out
	rm -f ft_printf_output.txt printf_output.txt
	touch ft_printf_output.txt printf_output.txt

run:
	./speed_out

clean:
	rm -f libftprintf.a libspeedtest.a speed_out
	rm -f ft_printf_output.txt printf_output.txt