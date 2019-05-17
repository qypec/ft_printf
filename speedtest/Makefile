# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 20:05:07 by yquaro            #+#    #+#              #
#    Updated: 2019/05/17 16:33:28 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = bigtest.c processing.c color.c print.c 
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
	rm -f ft_printf_output.txt printf_output.txt
	touch ft_printf_output.txt printf_output.txt

run:
	./speed_out

clean:
	rm -rf .obj
	rm -f libftprintf.a libspeedtest.a speed_out
	rm -f ft_printf_output.txt printf_output.txt