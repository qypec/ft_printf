# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 09:44:11 by qypec             #+#    #+#              #
#    Updated: 2019/07/25 03:45:26 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_includes/libft.mk

SOURCES = ft_abs.c ft_pow.c
OBJECTS = ft_abs.o ft_pow.o

NAME = libmath.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_math

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	rm *.o