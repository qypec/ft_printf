# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 13:11:11 by qypec             #+#    #+#              #
#    Updated: 2019/07/25 03:42:48 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_includes/libft.mk

SOURCES = ft_buffinit.c ft_buffdel.c ft_buffreload.c
OBJECTS = ft_buffinit.o ft_buffdel.o ft_buffreload.o

NAME = libbuff.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_buffer

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	rm *.o
	