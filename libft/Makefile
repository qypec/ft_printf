# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 19:26:56 by yquaro            #+#    #+#              #
#    Updated: 2019/05/02 17:44:37 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# Adds a character index to the archive

FLAGS = -Wall -Wextra -Werror
SOURCE = ft_*.c
OBJS = *.o
OBJDIR = .obj
LIBNAME = libft.a

all: $(LIBNAME)
$(LIBNAME):
	gcc -c -g $(FLAGS) $(SOURCE)
	mkdir $(OBJDIR)
	mv $(OBJS) $(OBJDIR)
	ar rc $(LIBNAME) $(OBJDIR)/$(OBJS)
	ranlib $(LIBNAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all
