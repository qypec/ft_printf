# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/07/24 12:21:20 by oargrave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# Adds a character index to the archive

# FLAGS = -Wall -Wextra -Werror
SOURCE = src/ft_printf.c src/color.c src/print_arg.c src/buffer_output.c src/add_in_glbuffer.c \
	src/bust.c src/print_date.c src/parse.c src/struct_spec.c src/is_it_something.c \
	src/print_diu.c src/ft_itoa_base.c src/print_char.c src/print_dl_dll.c src/parse.c src/print_int.c \
	src/print_float.c src/display_int.c src/rounding.c
OBJS = *.o
OBJDIR = .obj
NAME = libftprintf.a

all: $(NAME)
$(NAME):
	make -C libft/ re
	gcc -c -g $(SOURCE)  # не забыть про ФЛАГИ!!!!!
	mkdir $(OBJDIR)
	mv $(OBJS) $(OBJDIR)
	ar rc $(NAME) $(OBJDIR)/$(OBJS) libft/$(OBJDIR)/*.o
	ranlib $(NAME)
	gcc main.c -L. -lftprintf -o ft_printf # убрать

clean:
	make -C libft/ clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
