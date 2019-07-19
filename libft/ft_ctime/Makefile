# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 17:26:14 by yquaro            #+#    #+#              #
#    Updated: 2019/06/18 02:27:35 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# adds a character index to the archive

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
SOURCES = ft_uctime.c ft_ctime.c getdata.c getmonth.c get_temporarydata.c \
			struct_to_str.c
OBJECTS = ft_uctime.o ft_ctime.o getdata.o getmonth.o get_temporarydata.o \
			struct_to_str.o

NAME = libctime.a

all: $(SOURCES) print_echo $(NAME)
	
print_echo:
	@echo \*\*\* Compiling ft_ctime

.c.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

fclean: 
	@rm ../lib/$(NAME)
	@rm *.o