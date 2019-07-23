# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 13:54:33 by yquaro            #+#    #+#              #
#    Updated: 2019/07/23 15:04:18 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
SOURCES = ft_hashfunc.c ft_mapinsert.c ft_mapnew.c ft_putmap.c ht_list.c \
			ft_mapdelone.c ft_ismapitem.c ft_getvalue.c ft_mapdel.c
OBJECTS = ft_hashfunc.o ft_mapinsert.o ft_mapnew.o ft_putmap.o ht_list.o \
			ft_mapdelone.o ft_ismapitem.o ft_getvalue.o ft_mapdel.o

NAME = libhashtab.a

all: $(SOURCES) print_echo $(NAME)
	
print_echo:
	@echo \*\*\* Compiling ft_hashtab

.c.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	rm $(OBJECTS)

fclean: 
	rm ../lib/$(NAME)