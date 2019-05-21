# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 20:05:07 by yquaro            #+#    #+#              #
#    Updated: 2019/05/20 21:17:06 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = byonesymb_test.c bigstring_test.c processing.c color.c print.c 
OBJS = *.o
OBJDIR = .obj
NAME = libspeedtest.a

all:
	gcc -c $(SOURCE)
	mkdir $(OBJDIR)
	mv $(OBJS) $(OBJDIR)
	ar rc $(NAME) $(OBJDIR)/$(OBJS)
	ranlib $(NAME)
	gcc main.c -L. -lftprintf -lspeedtest -o speed_out
	rm -rf txt_files
	mkdir txt_files
	touch txt_files/ft_printf_output.txt txt_files/printf_output.txt

run:
	./speed_out

run_bigstring:
	./speed_out 2

clean:
	rm -rf .obj
	rm -f libftprintf.a libspeedtest.a speed_out
	rm -rf txt_files