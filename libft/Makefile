# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 19:26:56 by yquaro            #+#    #+#              #
#    Updated: 2019/05/06 17:08:46 by yquaro           ###   ########.fr        #
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
NAME = libft.a

all: $(NAME)
$(NAME):
	gcc -g -c $(FLAGS) $(SOURCE)
	mkdir $(OBJDIR)
	mv $(OBJS) $(OBJDIR)
	make -C ft_ctime/ all
	ar rc $(NAME) $(OBJDIR)/$(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
