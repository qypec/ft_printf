# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 13:54:33 by yquaro            #+#    #+#              #
#    Updated: 2019/07/25 03:44:06 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_includes/libft.mk

SOURCES = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_lstpushback.c \
			ft_listsize.c
OBJECTS = ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstnew.o ft_lstpushback.o \
			ft_listsize.o

NAME = liblist.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_list

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	rm *.o