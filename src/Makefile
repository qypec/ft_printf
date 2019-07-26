# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:07:18 by yquaro            #+#    #+#              #
#    Updated: 2019/07/26 18:03:32 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/printf.mk

SOURCES = ft_printf.c add_in_glbuffer.c color.c print_arg.c buffer_output.c \
	print_date.c parse.c struct_spec.c is_it_something.c \
	print_diu.c ft_itoa_base.c print_char.c print_dl_dll.c print_int.c \
	print_float.c display_int.c gspec.c rounding.c init_width.c 

OBJECTS = ft_printf.o add_in_glbuffer.o color.o print_arg.o buffer_output.o  \
	print_date.o parse.o struct_spec.o is_it_something.o \
	print_diu.o ft_itoa_base.o print_char.o print_dl_dll.o print_int.o \
	print_float.o display_int.o gspec.o rounding.o init_width.o

NAME = printf.a

all: print $(SOURCES) $(NAME)

print:
	@echo \*\*\* Compiling ft_printf

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f ../lib/$(NAME)



