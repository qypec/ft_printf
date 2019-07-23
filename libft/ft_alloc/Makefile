# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 09:13:41 by qypec             #+#    #+#              #
#    Updated: 2019/06/18 02:27:10 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
SOURCES = ft_realloc.c ft_memalloc.c ft_memdel.c ft_strdel.c
OBJECTS = ft_realloc.o ft_memalloc.o ft_memdel.o ft_strdel.o

NAME = liballoc.a

all: $(SOURCES) print_echo $(NAME)
	
print_echo:
	@echo \*\*\* Compiling ft_alloc

.c.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

fclean:
	@rm ../lib/$(NAME)
	@rm *.o