# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 17:26:14 by yquaro            #+#    #+#              #
#    Updated: 2019/05/04 19:19:14 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# adds a character index to the archive

FLAGS = -Wall -Wextra -Werror
SOURCE = ft_uctime.c ft_ctime.c getdata.c getmonth.c get_temporarydata.c struct_to_str.c
OBJS = ft_uctime.o ft_ctime.o getdata.o getmonth.o get_temporarydata.o struct_to_str.o
OBJDIR = ../.obj

all: 
	gcc -c $(FLAGS) $(SOURCE)
	mv $(OBJS) $(OBJDIR)
